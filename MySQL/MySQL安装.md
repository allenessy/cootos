MySQL下载地址：
[http://dev.mysql.com/downloads/mysql/](http://dev.mysql.com/downloads/mysql/)

我的系统是Windows 7 64bit 所以我下载了`mysql-5.6.12-winx64.zip`
解压到`D:\mysql`目录下
`D:\mysql\bin` 加入PATH系统变量。
用管理员模式打开cmd,进入D:\mysql目录执行：

    mysqld --install

安装完成。

    mysql -uroot

进入mysql看看


MySQL修改默认用户密码

    SELECT host,user,password FROM mysql.user;
    DROP USER ''@'localhost';
    UPDATE mysql.user set Password=password("123456") WHERE User="root";
    FLUSH PRIVILEGES;

