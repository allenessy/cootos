###SQLSTATE[HY000] [2002] No such file or directory
最近在CentOS 6.4 x64上面使用XAMPP的Apache、PHP组件，MySQL是单独安装的		
在PHP使用PDO MySQL连MySQL的使用，页面提示`SQLSTATE[HY000] [2002] No such file or directory` 		
折腾了几天不知道怎么解决，最后在一个博客找到了解决方案，特记录下来		
```bash
vi /opt/lampp/etc/php.ini
```
修改`php.ini`中`pdo_mysql.default_socket=/var/xxx/mysql.sock`,将其改成你自己的`mysql.sock`路径，例如`/tmp/mysql.sock`
```bash
pdo_mysql.default_socket=/var/lib/mysql/mysql.sock
mysql.default_socket=/var/lib/mysql/mysql.sock
mysqli.default_socket=/var/lib/mysql/mysql.sock
```
重启apache服务器
```bash
/opt/lampp/lampp stopapache
/opt/lampp/lampp startapache
```
刷新页面，恢复正常了.