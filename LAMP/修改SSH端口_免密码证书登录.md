如何添加禁止登录的用户

    useradd username -s /sbin/nologin     //通过SSH软件登录服务器，键入如下代码建立用户
    passwd username                       //设置用户密码

这样就建立了没有登录权限的用户。

vi /etc/ssh/sshd_config

    #Port 22                        //第13行  修改为Port 2222 指定SSH连接的端口号，不建议使用默认22端口
    Protocol 2                      //第21行  2,1允许SSH1和SSH2连接，建议设置成 Protocal 2
    #PermitRootLogin yes            //第42行  允许root登录
    #PermitEmptyPasswords no        //第65行    不允许空密码登录
    PasswordAuthentication yes  //第66行  改为 PasswordAuthentication no   取消密码认证登录

重启SSH

/etc/init.d/sshd restart      
        
配置防火墙，打开需要端口：      
vi /etc/sysconfig/iptables      

    iptables -P INPUT ACCEPT
    iptables -P FORWARD ACCEPT
    iptables -P OUTPUT ACCEPT
    iptables -F
    iptables -X
    iptables -Z
    iptables -F -t nat
    iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 80 -j ACCEPT
    iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1119 -j ACCEPT
    iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1812 -j ACCEPT
    iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1813 -j ACCEPT
    iptables -t nat -A POSTROUTING -o eth0  -j MASQUERADE
    iptables --table nat --append POSTROUTING --jump MASQUERADE
    /etc/init.d/iptables save
    /etc/init.d/iptables restart
    setenforce 0

添加NAT转发：

    iptables -t nat -A POSTROUTING -o eth0  -j MASQUERADE
    iptables -t nat -A POSTROUTING -o eth1  -j MASQUERADE

保存防火墙设置：

    /etc/init.d/iptables save
    /etc/init.d/iptables restart

查看NAT转发规则

    iptables -F -t nat
    iptables -L -n -v -t nat

创建公共密钥文件Public_key

    mkdir -pv /root/.ssh
    touch ~/.ssh/authorized_keys
    vi ~/.ssh/authorized_keys

