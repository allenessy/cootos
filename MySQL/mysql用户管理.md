创建无密码的MySQL用户

    CREATE USER '用户名'@'localhost';

创建明文密码的MySQL用户

    CREATE USER '用户名'@'localhost' IDENTIFIED BY '密码';

创建哈希值密码的MySQL用户

    SELECT password('密码');

得到密码的哈希值：

    *E04600BB4BC876C4A82BB0860EDE6F7829AE5D2A

设置哈希密码

    CREATE USER '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';

设置哈希密码

    CREATE USER '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';

查看MySQL用户

    use mysql
    SELECT host,user,password FROM user;

添加用户名和哈希值密码

    CREATE USER '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';

添加DBA授权用户

    GRANT ALL ON 数据库名.* TO '用户名'@'localhost';

添加MySQL用户，并授权

    GRANT ALL ON 数据库名.* TO '用户名'@'localhost' IDENTIFIED BY PASSWORD '*6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9';

重新加载授权表：

    FLUSH PRIVILEGES;

删除空用户

    DROP USER 'root'@'localhost';
    DROP USER 'root'@'::1';
    DROP USER 'root'@'127.0.0.1';

添加远程登录用户

    SELECT password('密码');
    GRANT ALL ON *.* TO '用户名'@'%' IDENTIFIED BY PASSWORD '哈希值密码';

打开远程登录端口(默认3306)

    iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 3306 -j ACCEPT
    /etc/init.d/iptables save
    /etc/init.d/iptables restart

添加远程登陆用户

    GRANT ALL ON *.* TO '用户名'@'%' IDENTIFIED BY '密码';
    FLUSH PRIVILEGES;


