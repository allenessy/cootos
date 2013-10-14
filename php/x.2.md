###SAE 安装WordPress 3.5.1
下载最新的wordpress [https://cn.wordpress.org/](https://cn.wordpress.org/)

第一步      
SAE是没有写权限的，所以wp-config.php是我们要提前准备好的。
```php
/** WordPress数据库的名称 */
define('DB_NAME', SAE_MYSQL_DB);

/** MySQL数据库用户名 */
define('DB_USER', SAE_MYSQL_USER);

/** MySQL数据库密码 */
define('DB_PASSWORD', SAE_MYSQL_PASS);

/** MySQL主机名 */
define('DB_HOST', SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT);
```
在根目录新建一个config.yaml，内容如下
```yaml
handle:
- rewrite:if (!is_file() && !is_dir() && path ~ "^/(.*)") goto "index.php/$1"
```

第二步
SAE没有写权限，但是它为我们提供了一个Storage来上传附件，先到SAE的后台新建一个Domain，我的是blog
打开wp-include/funciton.php文件，找到
```php
$baseurl = $url;
```
在它后面添加
```php
$basedir = $dir = 'saestor://cootos.sinaapp.com/wp-content/uploads';
```

WordPress默认的是`wp-content/uploads`，这里可以根据自己喜好来填写，但是必须要和WordPress后台的默认上传路径保持一致。还需要到后台修改文件的完整 URL 地址为你的Storage最终地址，例如我的 `http://cootos.sinaapp.com/wp-content/uploads`

第三步

既然SAE没有提供修改代码的权限，那么更新对新手用户来说显得太“奢侈”了，而且这个功能会无端的消耗掉你的豆豆
编辑`wp-include/update.php`，移到底部，你会发现一大串的
```php
add_action(....);
add_action( 'load-update-core.php', 'wp_version_check' );
add_action( 'load-update-core.php', 'wp_update_themes' );
```
保留这两行，其他全部删除，在文件尾部再加入一句
```php
add_action( 'load-update-core.php', 'wp_update_plugins' );
```
这样只有你手动去点击 仪表盘->更新的时候，才会检测更新。

第四步

这好像是3.5才新加入的代码，用来判断上传文件的执行权限来提高安全性，SAE根本无需考虑代码安全性，它们的存在却会让系统报错。
```php
// Set correct file permissions
$stat = stat( dirname( $new_file ));
$perms = $stat['mode'] & 0000666;
@ chmod( $new_file, $perms );
````
找到上面这段代码，消灭它们，`wp-admin/include/file.php`中有2处，`wp-include/class-wp-image-editor-gd.php中`有一处，其他肯定还有，但是目前没有发现他们对系统有什么影响，只要找到这3处，删除代码即可。

第五步

在WordPress后台设置了图片尺寸后，如果上传的图片大于这个尺寸，就会自动裁剪，而在SAE上却不会，翻来覆去的找了下原因，终于让我找到了。

罪魁祸首在imagepng imagejpeg不能用Wrappers

所以我们要修改缩略图的输出方式，打开`wp-include/class-wp-image-editor.php`找到如下一句代码
```php
$result = call_user_func_array( $function, $arguments );
```
修改为
```php
//$result = call_user_func_array( $function, $arguments );
$arguments_temp = $arguments;
$arguments_temp[1] = SAE_TMP_PATH.'image_temp.dat';
$result = call_user_func_array( $function, $arguments_temp );
if ($result) {
file_put_contents($arguments[1],file_get_contents(SAE_TMP_PATH.'image_temp.dat'));
}
```
到这里，WordPress For SAE 的移植已经基本结束了。

开启SAE的MemoCache缓存

```php
<?php
/*
Plugin Name: Memcached
Description: Memcached backend for the WP Object Cache.
Version: 2.0.1
Plugin URI: http://wordpress.org/extend/plugins/memcached/
Author: Ryan Boren, Denis de Bernardy, Matt Martz
Install this file to wp-content/object-cache.php
*/

function wp_cache_add($key, $data, $flag = '', $expire = 0) {
global $wp_object_cache;

return $wp_object_cache->add($key, $data, $flag, $expire);
}

function wp_cache_incr($key, $n = 1, $flag = '') {
global $wp_object_cache;

return $wp_object_cache->incr($key, $n, $flag);
}

function wp_cache_decr($key, $n = 1, $flag = '') {
global $wp_object_cache;

return $wp_object_cache->decr($key, $n, $flag);
}

function wp_cache_close() {
global $wp_object_cache;

return $wp_object_cache->close();
}

function wp_cache_delete($id, $flag = '') {
global $wp_object_cache;

return $wp_object_cache->delete($id, $flag);
}

function wp_cache_flush() {
global $wp_object_cache;

return $wp_object_cache->flush();
}

function wp_cache_get($id, $flag = '') {
global $wp_object_cache;

return $wp_object_cache->get($id, $flag);
}

function wp_cache_init() {
global $wp_object_cache;

$wp_object_cache = new WP_Object_Cache();
}

function wp_cache_replace($key, $data, $flag = '', $expire = 0) {
global $wp_object_cache;

return $wp_object_cache->replace($key, $data, $flag, $expire);
}

function wp_cache_set($key, $data, $flag = '', $expire = 0) {
global $wp_object_cache;

if ( defined('WP_INSTALLING') == false )
return $wp_object_cache->set($key, $data, $flag, $expire);
else
return $wp_object_cache->delete($key, $flag);
}

function wp_cache_add_global_groups( $groups ) {
global $wp_object_cache;

$wp_object_cache->add_global_groups($groups);
}

function wp_cache_add_non_persistent_groups( $groups ) {
global $wp_object_cache;

$wp_object_cache->add_non_persistent_groups($groups);
}

class WP_Object_Cache {
var $global_groups = array ('users', 'userlogins', 'usermeta', 'site-options', 'site-lookup', 'blog-lookup', 'blog-details', 'rss');

var $no_mc_groups = array( 'comment', 'counts' );

var $autoload_groups = array ('options');

var $cache = array();
var $mc = array();
var $stats = array();
var $group_ops = array();

var $cache_enabled = true;
var $default_expiration = 0;

function add($id, $data, $group = 'default', $expire = 0) {
$key = $this->key($id, $group);

if ( in_array($group, $this->no_mc_groups) ) {
$this->cache[$key] = $data;
return true;
} elseif ( isset($this->cache[$key]) && $this->cache[$key] !== false ) {
return false;
}

$mc =& $this->get_mc($group);
$expire = ($expire == 0) ? $this->default_expiration : $expire;
$result = $mc->add($key, $data, false, $expire);

if ( false !== $result ) {
@ ++$this->stats['add'];
$this->group_ops[$group][] = "add $id";
$this->cache[$key] = $data;
}

return $result;
}

function add_global_groups($groups) {
if ( ! is_array($groups) )
$groups = (array) $groups;

$this->global_groups = array_merge($this->global_groups, $groups);
$this->global_groups = array_unique($this->global_groups);
}

function add_non_persistent_groups($groups) {
if ( ! is_array($groups) )
$groups = (array) $groups;

$this->no_mc_groups = array_merge($this->no_mc_groups, $groups);
$this->no_mc_groups = array_unique($this->no_mc_groups);
}

function incr($id, $n, $group) {
$key = $this->key($id, $group);
$mc =& $this->get_mc($group);

return $mc->increment($key, $n);
}

function decr($id, $n, $group) {
$key = $this->key($id, $group);
$mc =& $this->get_mc($group);

return $mc->decrement($key, $n);
}

function close() {

foreach ( $this->mc as $bucket => $mc )
$mc->close();
}

function delete($id, $group = 'default') {
$key = $this->key($id, $group);

if ( in_array($group, $this->no_mc_groups) ) {
unset($this->cache[$key]);
return true;
}

$mc =& $this->get_mc($group);

$result = $mc->delete($key);

@ ++$this->stats['delete'];
$this->group_ops[$group][] = "delete $id";

if ( false !== $result )
unset($this->cache[$key]);

return $result;
}

function flush() {
// Don't flush if multi-blog.
if ( function_exists('is_site_admin') || defined('CUSTOM_USER_TABLE') && defined('CUSTOM_USER_META_TABLE') )
return true;

$ret = true;
foreach ( array_keys($this->mc) as $group )
$ret &= $this->mc[$group]->flush();
return $ret;
}

function get($id, $group = 'default') {
$key = $this->key($id, $group);
$mc =& $this->get_mc($group);

if ( isset($this->cache[$key]) )
$value = $this->cache[$key];
else if ( in_array($group, $this->no_mc_groups) )
$value = false;
else
$value = $mc->get($key);

@ ++$this->stats['get'];
$this->group_ops[$group][] = "get $id";

if ( NULL === $value )
$value = false;

$this->cache[$key] = $value;

if ( 'checkthedatabaseplease' == $value )
$value = false;

return $value;
}

function get_multi( $groups ) {
/*
format: $get['group-name'] = array( 'key1', 'key2' );
*/
$return = array();
foreach ( $groups as $group => $ids ) {
$mc =& $this->get_mc($group);
foreach ( $ids as $id ) {
$key = $this->key($id, $group);
if ( isset($this->cache[$key]) ) {
$return[$key] = $this->cache[$key];
continue;
} else if ( in_array($group, $this->no_mc_groups) ) {
$return[$key] = false;
continue;
} else {
$return[$key] = $mc->get($key);
}
}
if ( $to_get ) {
$vals = $mc->get_multi( $to_get );
$return = array_merge( $return, $vals );
}
}
@ ++$this->stats['get_multi'];
$this->group_ops[$group][] = "get_multi $id";
$this->cache = array_merge( $this->cache, $return );
return $return;
}

function key($key, $group) {
if ( empty($group) )
$group = 'default';

if ( false !== array_search($group, $this->global_groups) )
$prefix = $this->global_prefix;
else
$prefix = $this->blog_prefix;

return preg_replace('/\s+/', '', "$prefix$group:$key");
}

function replace($id, $data, $group = 'default', $expire = 0) {
$key = $this->key($id, $group);
$expire = ($expire == 0) ? $this->default_expiration : $expire;
$mc =& $this->get_mc($group);
$result = $mc->replace($key, $data, false, $expire);
if ( false !== $result )
$this->cache[$key] = $data;
return $result;
}

function set($id, $data, $group = 'default', $expire = 0) {
$key = $this->key($id, $group);
if ( isset($this->cache[$key]) && ('checkthedatabaseplease' == $this->cache[$key]) )
return false;
$this->cache[$key] = $data;

if ( in_array($group, $this->no_mc_groups) )
return true;

$expire = ($expire == 0) ? $this->default_expiration : $expire;
$mc =& $this->get_mc($group);
$result = $mc->set($key, $data, false, $expire);

return $result;
}

function colorize_debug_line($line) {
$colors = array(
'get' => 'green',
'set' => 'purple',
'add' => 'blue',
'delete' => 'red');

$cmd = substr($line, 0, strpos($line, ' '));

$cmd2 = "<span style='color:{$colors[$cmd]}'>$cmd</span>";

return $cmd2 . substr($line, strlen($cmd)) . "\n";
}

function stats() {
echo "<p>\n";
foreach ( $this->stats as $stat => $n ) {
echo "<strong>$stat</strong> $n";
echo "<br/>\n";
}
echo "</p>\n";
echo "<h3>Memcached:</h3>";
foreach ( $this->group_ops as $group => $ops ) {
if ( !isset($_GET['debug_queries']) && 500 < count($ops) ) {
$ops = array_slice( $ops, 0, 500 );
echo "<big>Too many to show! <a href='" . add_query_arg( 'debug_queries', 'true' ) . "'>Show them anyway</a>.</big>\n";
}
echo "<h4>$group commands</h4>";
echo "<code>\n";
$lines = array();
foreach ( $ops as $op ) {
$lines[] = $this->colorize_debug_line($op);
}
print_r($lines);
echo "</code>\n";
}

if ( $this->debug )
var_dump($this->memcache_debug);
}

function &get_mc($group) {
if ( isset($this->mc[$group]) )
return $this->mc[$group];
return $this->mc['default'];
}

function failure_callback($host, $port) {
//error_log("Connection failure for $host:$port\n", 3, '/tmp/memcached.txt');
}

function __construct() {
self::WP_Object_Cache();
}

function WP_Object_Cache() {
global $memcached_servers;

if ( isset($memcached_servers) )
$buckets = $memcached_servers;
else
$buckets = array('127.0.0.1');

reset($buckets);
if ( is_int(key($buckets)) )
$buckets = array('default' => $buckets);

foreach ( $buckets as $bucket => $servers) {
$this->mc[$bucket] = memcache_init();
}

global $blog_id, $table_prefix;
$this->global_prefix = ( is_multisite() || defined('CUSTOM_USER_TABLE') && defined('CUSTOM_USER_META_TABLE') ) ? '' : $table_prefix;
$this->blog_prefix = ( is_multisite() ? $blog_id : $table_prefix ) . ':';

$this->cache_hits =& $this->stats['get'];
$this->cache_misses =& $this->stats['add'];
}
}
?>
```
移植hyper-cache缓存插件 SAE的MC缓存是比较吃豆豆的，而相比较新浪自主研发的KVDB的价格却少得可怜，所以我们可以把hyper-cache的缓存写入到KVDB中去，KVDB中只有两个属性，有点类似于Array，既键名与键值，我们可以通过改写SAE提供的SaeKVClient类来给数据加入一个时间戳，用来判断缓存到期时间。

这个类是从官方论坛收集的，根据需要修改了一下，源码如下
```php

<?php
class MyKVClient extends SaeKVClient
{
private $_inited = false;
/*
*/
public function init()
{
$_inited = true;
return parent::init();
}
public function set($k, $v=null, $timeout = 0)
{
if(!@$_inited)
{
$this->init();
}
if(!empty($timeout))
{
$timeout = time()+$timeout;
}
$v = array('d'=>$v,'t'=>$timeout);
return parent::set($k,$v);
}
public function get($k)
{
if(!@$_inited)
{
$this->init();
}
$v = parent::get($k);
if($v['t']<time() && !empty($v['t']))
{
$this->delete($k);
return false;
}
return $v['d'];
}
public function gett($k)
{
$v = parent::get($k);
return $v['t'];
}
public function delete($k)
{
if(!@$_inited)
{
$this->init();
}
return parent::delete($k);
}
public function mget($ks)
{
if(!@$_inited)
{
$this->init();
}
$v = parent::mget($ks);
if(!empty($v))
{
foreach($v as $key=>$val)
{
if($val['t']<time() && !empty($val['t']))
{
unset($v[$key]);
$this->delete($key);
}
else
{
$v[$key] = $val['d'];
}
}
}
return $v;
}
public function pkrget($k,$c=1,$start_key=NULL)
{
if(!@$_inited)
{
$this->init();
}
$v = parent::pkrget($k,$c,$start_key);
if(!empty($v))
{
foreach($v as $key=>$val)
{
if($val['t']<time() && !empty($val['t']))
{
unset($v[$key]);
$this->delete($key);
}
else
{
$v[$key] = $val['d'];
}
}
}
return $v;
}
public function pkrdelete($k,$c=1)
{
if(!@$_inited)
{
$this->init();
}
$v = parent::pkrget($k,$c);
if(!empty($v))
{
foreach($v as $key=>$val)
{
$this->delete($key);
}
}
return;
}
}
```
如果在非SAE环境中安装hyper-cache，它会在`wp-content`目录生成一个`advanced-cache.php`来保存配置，最好还是能在其他环境中配置好，然后再把这个文件上传到SAE来，设置$hyper_cache_path为一个前缀，而不是路径，例如`$hyper_cache_path = 'hypercache_'`;，这样我们可以通过pkrget和pkrdelete来操作hyper-cache的缓存。
`options.php`有个777的提示需要屏蔽，其他修改都在`cache.php`和`plugin.php`中，具体修改太过繁琐就不一一贴出来了。

数据库缓存插件 db-cache-reloaded-fix MYSQL也是资源大户，能省则省，同 hyper-cache 一样 db-cache-reloaded-fix 在非SAE环境中也会向`wp-content`中写入配置文件，一个`db-config.ini`，一个`db.php`。

`db.php`中`define( 'DBCR_CACHE_DIR', DBCR_PATH.'/cache' )`;也最好修改成前缀，用来识别，我的是`define( 'DBCR_CACHE_DIR', 'db-cache-reloaded-fix' )`;

其他的修改都在`db-functions.php`里了。

好累，先到这里吧。
