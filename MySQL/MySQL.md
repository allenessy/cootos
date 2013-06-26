MySQL下载地址：
<a href="http://dev.mysql.com/downloads/mysql/" target="_blank">http://dev.mysql.com/downloads/mysql/</a>

我的系统是Windows 7 64bit 所以我下载了mysql-5.6.12-winx64.zip<br>
解压到D:\mysql目录下<br>
D:\mysql\bin 加入PATH系统变量。<br>
用管理员模式打开cmd,进入D:\mysql目录执行：<br>
<pre>
mysqld --install<br>
</pre>
安装完成。<br/>
<pre>
mysql -uroot<br/>
</pre>
进入mysql看看<br/>
<br/>

MySQL修改默认用户密码
<pre>
SELECT host,user,password FROM mysql.user;
DROP USER ''@'localhost';
UPDATE mysql.user set Password=password("123456") WHERE User="root";
FLUSH PRIVILEGES;
</pre>
