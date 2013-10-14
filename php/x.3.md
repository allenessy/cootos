###BAE 安装 WordPress 3.5.1
下载最新的wordpress [https://cn.wordpress.org/](https://cn.wordpress.org/)

配置wp-config.php示范代码（需修改$dbname和$bcs_bucket）

```php
< ?php
//创建的云数据库名称和申请的bucket
$dbname = "NmbmJnwQDieJRxUDBmiJ";
$table_prefix = 'wp';
$bcs_bukect = 'baeueditor';
?>
< ?php
//从环境变量中获得数据库的主机地址、用户名和密码
$ip = getenv('HTTP_BAE_ENV_ADDR_SQL_IP');
$port = getenv('HTTP_BAE_ENV_ADDR_SQL_PORT');
$host = $ip.":".$port;
$user = getenv('HTTP_BAE_ENV_AK');
$pass = getenv('HTTP_BAE_ENV_SK');
// ** MySQL 设置 - 具体信息来自您正在使用的主机 ** //
/** WordPress 数据库的名称 */
define('DB_NAME', $dbname);
/** MySQL 数据库用户名 */
define('DB_USER', $user);
/** MySQL 数据库密码 */
define('DB_PASSWORD', $pass);
/** MySQL 主机 */
define('DB_HOST', $host);
define('BCS_BUCKET', $bcs_bukect);
/** 创建数据表时默认的文字编码 */
define('DB_CHARSET', 'utf8');
/** 数据库整理类型。如不确定请勿更改 */
define('DB_COLLATE', '');
/**#@+
* 身份认证密匙设定。
*
* 您可以随意写一些字符
* 或者直接访问 {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org 私钥生成服务}，
* 任何修改都会导致 cookie 失效，所有用户必须重新登录。
*
* @since 2.6.0
*/
define('AUTH_KEY', '$%^&*');
define('SECURE_AUTH_KEY', '123231');
define('LOGGED_IN_KEY', '21');
define('NONCE_KEY', '212');
define('AUTH_SALT', '21332');
define('SECURE_AUTH_SALT', '324');
define('LOGGED_IN_SALT', '3234');
define('NONCE_SALT', '24');
/**#@-*/
/**
* WordPress 数据表前缀。
*
* 如果您有在同一数据库内安装多个 WordPress 的需求，请为每个 WordPress 设置不同的数据表前缀。
* 前缀名只能为数字、字母加下划线。
*/
/**
* WordPress 语言设置，中文版本默认为中文。
*
* 本项设定能够让 WordPress 显示您需要的语言。
* wp-content/languages 内应放置同名的 .mo 语言文件。
* 要使用 WordPress 简体中文界面，只需填入 zh_CN。
*/
define('WPLANG', 'zh_CN');
/**
* 开发者专用：WordPress 调试模式。
*
* 将这个值改为“true”，WordPress 将显示所有用于开发的提示。
* 强烈建议插件开发者在开发环境中启用本功能。
*/
define('WP_DEBUG', false);
/* 好了！请不要再继续编辑。请保存本文件。使用愉快！ */
/** WordPress 目录的绝对路径。 */
/****************************************
*use proxy to visit network
****************************************/
define('WP_PROXY_HOST', getenv('HTTP_BAE_ENV_ADDR_FETCHURL'));
define('WP_PROXY_USERNAME', getenv('HTTP_BAE_ENV_AK'));
define('WP_PROXY_PASSWORD', getenv('HTTP_BAE_ENV_SK'));
if( !defined('ABSPATH') )
define('ABSPATH', dirname(__FILE__) . '/');
/** 设置 WordPress 变量和包含文件。 */
require_once(ABSPATH . 'wp-settings.php');
?>
```
修改mysql服务

打开 `wp-admin/includes/file.php` 文件，首先查找 `function wp_handle_upload( &$file, $overrides = false, $time = null )`函数
然后，在这个 函数 找到 这行代码 
```php
$filename = wp_unique_filename( $uploads['path'], $file['name'], $unique_filename_callback );
```
这行代码以下的代码删改为：
需要删除的代码：
```php
// Move the file to the uploads dir
$new_file = $uploads['path'] . "/$filename";
if ( false === @ move_uploaded_file( $file['tmp_name'], $new_file ) )
return $upload_error_handler( $file, sprintf( __('The uploaded file could not be moved to %s.' ), $uploads['path'] ) );
// Set correct file permissions
$stat = stat( dirname( $new_file ));
$perms = $stat['mode'] & 0000666;
@ chmod( $new_file, $perms );
// Compute the URL
$url = $uploads['url'] . "/$filename";
if ( is_multisite() )
delete_transient( 'dirsize_cache' );
return apply_filters( 'wp_handle_upload', array( 'file' => $new_file,'url' => $url, 'type' => $type ), 'upload' );
```
删除后，添加的代码：
```php
$tmp_file = wp_tempnam($filename);
// Move the file to the uploads dir
if ( false === @ move_uploaded_file( $file['tmp_name'], $tmp_file ) )
return $upload_error_handler( $file, sprintf( __('The uploaded file could not be moved to %s.' ), $uploads['path'] ) );
// If a resize was requested, perform the resize.
$image_resize = isset( $_POST['image_resize'] ) && 'true' == $_POST['image_resize'];
$do_resize = apply_filters( 'wp_upload_resize', $image_resize );
$size = @getimagesize( $tmp_file );
if ( $do_resize && $size ) {
$old_temp = $tmp_file;
$tmp_file = image_resize( $tmp_file, (int) get_option('large_size_w'), (int) get_option('large_size_h'), 0, 'resized');
if ( ! is_wp_error($tmp_file) ) {
unlink($old_temp);
} else {
$tmp_file = $old_temp;
}
}
//新版采用百度云存储
//上传到云存储
$bucket = constant('BCS_BUCKET');
$opt = array();
$baidu_bcs = new BaiduBCS();
$object = "/$filename";
$fileUpload = $tmp_file;
if( !file_exists($fileUpload) )
{
die('file is not existed!!!!!!!!!!!!!');
}
$re = $baidu_bcs->create_object ( $bucket, $object, $fileUpload, $opt);
trigger_error( print_r($re, true) );
unlink($tmp_file);
$url = $baidu_bcs->generate_get_object_url($bucket, $object);
//echo '??????'; exit;
if ( is_multisite() )
delete_transient( 'dirsize_cache' );
//exit("$new_file !! $url");
return apply_filters( 'wp_handle_upload', array( 'file' => $new_file,'url' => $url, 'type' => $type ), 'upload' );
```
出现乱码修改方法

在`wp-includes`文件夹下找到wp-db.php文件，使用文字编辑器打开，在文件第1063行 `$this->select( $this->dbname,$this->dbh );` 后面加上：`$this->query("set names utf8");` 然后重新上传到云服务上，使用。（如果您已创建了数据库，请先删除原来创建的数据库，如果不删除，官方文字依然是乱码）请一定注意。

替换百度`wp-ueditor`编辑器方法

百度在wordpress开发了一个非常强大的编辑软件，附件wp-ueditor.zip,具体操作方法，将文件解压到`wp-content\plugins`目录下，在打开wordpress，`仪表盘`—-`插件`—–`UEditor`（点击下方的启用），即可在文章编辑页面中使用，用用你就知道它有多么的强大了，很轻松搞定图片上传和插入到文章中的问题。（推荐使用，因为默认编辑器上传的图片会变成超链接)
[http://ueditor.baidu.com/website/](http://ueditor.baidu.com/website/)

无法连接数据库解决方法

出现 建立数据库连接时出错 但再次刷新下就又可以了。
经过大量的测试 在 `wp-config.php` 的 尾行 加一行
```php
define('WP_ALLOW_REPAIR', true);
```
我的就是这么解决的。


