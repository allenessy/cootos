###mod_auth_mysql
#####svn数据库认证方法
1.apache认证方法
平时上网访问一些网站的某些资源时，浏览器弹出一个对话框，要求输入用户名和密码来获取对资源的访问。这就是用户认证的一种技术。如在浏览器中访问SAE的SVN仓库如下提示一般：
浏览器的用户认证技术一般是基于“用户名+密码”的形式，服务端根据二者的对应关系控制着所有登录用户的合法性，其目的是仅让合法用户以合法的权限访问服务端资源。
SVN通用搭建方式是以Apache作为网络服务器，通过mod_dav_svn模块，操作SVN数据仓库，为用户提供版本服务。在这种搭建模式下用户可直接采用Apache的认证系统，比如使用文本文件，或者MSQL、Oracle等数据库，或者LDAP等等认证方法。对于大型SVN应用系统而言，搭建LDAP服务器来管理用户权限，更为合理，这也是我推荐的认证架构。但对于小企业或者个人用户来说，采用MySQL集中授权方式要简单方便，本文用来记录我对这种方式的摸索经历。

2.mod_authz_mysql的安装
下载mod_authz_mysql：
[http://nchc.dl.sourceforge.net/project/modauthmysql/modauthmysql/3.0.0/mod_auth_mysql-3.0.0.tar.gz](http://nchc.dl.sourceforge.net/project/modauthmysql/modauthmysql/3.0.0/mod_auth_mysql-3.0.0.tar.gz)

使用如下命令进行编译：
如果MySQL安装在可搜索路径下，用如下方法编译
```bash
/usr/local/apache2/bin/apxs -c -lmysqlclient -lm -lz mod_auth_mysql.c
```
如果MySQL安装在其他路径下，我们需要制定MySQL库的路径
```bash
/usr/local/apache2/bin/apxs -c -I/usr/local/mysql/include -L/usr/local/mysql/lib -lmysqlclient_r -lm -lz mod_auth_mysql.c
```
命令行上可以同时指定多个库路径，假如按上述方法编译提醒找不到zlib库，可按如下方法编译
```bash
/usr/local/apache2/bin/apxs -c -I/usr/local/mysql/include -L/usr/local/mysql/lib -L/usr/local/zlib -lmysqlclient_r -lm -lz mod_auth_mysql.c
```
但非常不幸的是，在安装mod_authz_mysql3.0.0版本时，无论采用上述哪种方法，都会出现如下一堆乱七八糟的错误：
```bash
/usr/local/apache2/bin/apxs -c -lmysqlclient -lm -lz mod_auth_mysql.c
```
```bash
/local/mysql/include -c -o mod_auth_mysql.lo mod_auth_mysql.c && touch mod_auth_mysql.slo
```
```bash
mod_auth_mysql.c: In function 'format_remote_ip':
mod_auth_mysql.c:908: error: 'conn_rec' has no member named 'remote_ip'
mod_auth_mysql.c: In function 'mysql_check_auth':
mod_auth_mysql.c:1273: warning: implicit declaration of function 'ap_requires'
mod_auth_mysql.c:1273: warning: initialization makes pointer from integer without a cast
apxs:Error: Command failed with rc=65536
```
.....此处省略十万八千个字
网上给出的解决方法是要给mod_auth_mysql.c打个补丁，该补丁可在这里下载到：
[mod_auth_mysql-300-apache-22.patch](mod_auth_mysql-300-apache-22.patch)

将该补丁文件放置到mod_authz_mysql的目录里，执行如下打补丁命令：
```bash
patch < mod_auth_mysql-300-apache-22.patch
```

打补丁之后，我们按原来的编译命令重新编译
```bash
vi mod_auth_mysql.c
```
找到第908行 remote_ip修改为client_ip
修改完重新编译
```bash
/usr/local/apache2/bin/apxs -c -I/usr/local/mysql/include -L/usr/local/mysql/lib -lmysqlclient_r -lm -lz mod_auth_mysql.c
```
```bash
/usr/local/apr/build-1/libtool --silent --mode=compile gcc -std=gnu99 -prefer-pic -DLINUX=2 -D_REENTRANT -D_GNU_SOURCE -g -O2 -pthread -I/usr/local/apache2/include -I/usr/local/apr/include/apr-1 -I/usr/local/apr-util/include/apr-1 -I/usr/local/mysql/include -c -o mod_auth_mysql.lo mod_auth_mysql.c && touch mod_auth_mysql.slo
mod_auth_mysql.c: In function 'mysql_check_auth':
mod_auth_mysql.c:1273: warning: implicit declaration of function 'ap_requires'
mod_auth_mysql.c:1273: warning: initialization makes pointer from integer without a cast
/usr/local/apr/build-1/libtool --silent --mode=link gcc -std=gnu99 -o mod_auth_mysql.la -L/usr/local/mysql/lib -lmysqlclient_r -lm -lz -rpath /usr/local/apache2/modules -module -avoid-version mod_auth_mysql.lo
```
提示以上错误，

这时一般都可以成功了。检视下/apache/modules目录下是否有mod_authz_mysql.so文件，如果没有，则手工从mod_authz_mysql的编译路径下拷贝过去即可。自此mod_authz_mysql编译算是告一段落了，下面开始配置和使用之旅。
