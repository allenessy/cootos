#!/bin/sh
rpm -Uvh http://mirrors.yun-idc.com/epel/6/i386/epel-release-6-8.noarch.rpm
yum update -y
yum repolist
iptables -P INPUT ACCEPT
iptables -P FORWARD ACCEPT
iptables -P OUTPUT ACCEPT
iptables -F
iptables -X
iptables -Z
iptables -F -t nat
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 21 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 22 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 47 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 80 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 443 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1119 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1701 -j ACCEPT
iptables -A INPUT -m state --state NEW -m udp -p udp --dport 1701 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1723 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1812 -j ACCEPT
iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 1813 -j ACCEPT
iptables -A INPUT -i ppp+ -j ACCEPT
iptables -A OUTPUT -o ppp+ -j ACCEPT
iptables -A INPUT -p tcp --dport 1723 -j ACCEPT
iptables -A INPUT -p 47 -j ACCEPT
iptables -A OUTPUT -p 47 -j ACCEPT
iptables -A FORWARD -j ACCEPT
iptables -A POSTROUTING -t nat -o ppp+ -j MASQUERADE
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
iptables --table nat --append POSTROUTING --jump MASQUERADE
/etc/init.d/iptables save
/etc/init.d/iptables restart
setenforce 0
echo -e "#SELINUX=enforcing\n#SELINUXTYPE=targeted\nSELINUX=disabled\nSETLOCALDEFS=0" > /etc/selinux/config
rm -rf /web
mkdir -p /web
yum -y install httpd
sed -i '276s/.*/ServerName 127.0.0.1:80/' /etc/httpd/conf/httpd.conf
sed -i '292s/.*/DocumentRoot "\/web"/' /etc/httpd/conf/httpd.conf
sed -i '317s/.*/<Directory "\/web"> /' /etc/httpd/conf/httpd.conf
sed -i '44s/.*/ServerTokens Prod/' /etc/httpd/conf/httpd.conf
sed -i '536s/.*/ServerSignature Off/' /etc/httpd/conf/httpd.conf
sed -i '331s/.*/Options Includes ExecCGI FollowSymLinks/' /etc/httpd/conf/httpd.conf
sed -i '796s/.*/AddHandler cgi-script .cgi .pl/' /etc/httpd/conf/httpd.conf
sed -i '338s/.*/AllowOverride All/' /etc/httpd/conf/httpd.conf
sed -i '554s/.*/Options MultiViews FollowSymLinks/' /etc/httpd/conf/httpd.conf
sed -i '402s/.*/DirectoryIndex index.html index.htm Default.html Default.htm index.php Default.php index.html.var/' /etc/httpd/conf/httpd.conf
sed -i '76s/.*/KeepAlive On/' /etc/httpd/conf/httpd.conf
sed -i '76s/.*/MaxKeepAliveRequests 1000/' /etc/httpd/conf/httpd.conf
chkconfig httpd on

yum -y install mysql mysql-server
/etc/init.d/mysqld start
chkconfig mysqld on
\cp -f /usr/share/mysql/my-medium.cnf   /etc/my.cnf
yum -y install php
yum -y install php-mysql php-gd libjpeg* php-imap php-ldap php-odbc php-pear php-xml php-xmlrpc php-mbstring php-mcrypt php-bcmath php-mhash libmcrypt
/etc/init.d/mysqld restart
/etc/init.d/httpd restart
sed -i '946s/.*/date.timezone = PRC/' /etc/php.ini
sed -i '432s/.*/expose_php = Off/' /etc/php.ini
sed -i '745s/.*/magic_quotes_gpc = On/' /etc/php.ini
sed -i '229s/.*/short_open_tag = ON/' /etc/php.ini
rm -rf /web/index.php
touch /web/index.php
chmod 755 -R /etc/pptpd.conf
cat > /web/index.php <<EOF
<?php
phpinfo();
?>
EOF
/etc/init.d/mysqld restart
/etc/init.d/httpd restart

echo "setting MySQL password:"

mysql_secure_installation
