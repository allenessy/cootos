创建无密码的MySQL用户
<pre>
CREATE USER '用户名'@'localhost'
</pre>

创建明文密码的MySQL用户
<pre>
CREATE USER '用户名'@'localhost' IDENTIFIED BY '密码';
</pre>
创建哈希值密码的MySQL用户
<pre>
SELECT password('密码');
</pre>
得到密码的哈希值：
<pre>
*E04600BB4BC876C4A82BB0860EDE6F7829AE5D2A
</pre>
设置哈希密码
<pre>
CREATE USER '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';
</pre>
设置哈希密码
<pre>
CREATE USER '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';
</pre>
查看MySQL用户
<pre>
use mysql
SELECT host,user,password FROM user;
</pre>
添加用户名和哈希值密码
<pre>
CREATE USER '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';
</pre>
添加DBA授权用户
<pre>
GRANT ALL ON 数据库名.* TO '用户名'@'localhost';
</pre>
添加MySQL用户，并授权
<pre>
GRANT ALL ON 数据库名.* TO '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';
</pre>
重新加载授权表：
<pre>
FLUSH PRIVILEGES;
</pre>
删除空用户
<pre>
DROP USER 'root'@'localhost';
DROP USER 'root'@'::1';
DROP USER 'root'@'127.0.0.1';
</pre>
添加远程登录用户
<pre>
SELECT password('密码');
GRANT ALL ON *.* TO '用户名'@'%' IDENTIFIED BY PASSWORD '哈希值密码';
</pre>
打开远程登录端口(默认3306)
<pre>
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 3306 -j ACCEPT
/etc/init.d/iptables save
/etc/init.d/iptables restart
</pre>
<pre>
GRANT ALL ON *.* TO '用户名'@'%' IDENTIFIED BY '密码';
FLUSH PRIVILEGES;
</pre>

