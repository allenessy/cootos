#!/bin/sh
yum -y install wget
mkdir -pv /allen
cd /allen
wget http://mirrors.163.com/.help/CentOS6-Base-163.repo
\cp -f /etc/yum.repos.d/CentOS-Base.repo /etc/yum.repos.d/CentOS-Base.repo_bak
rm -rf /etc/yum.repos.d/CentOS-Base.repo
\cp -f CentOS6-Base-163.repo /etc/yum.repos.d/CentOS-Base.repo
yum makecache
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
sed -i 's/#Port 22/Port 1119/g' /etc/ssh/sshd_config
sed -i 's/PermitEmptyPasswords no/#PermitEmptyPasswords no/g' /etc/ssh/sshd_config
sed -i 's/PermitRootLogin yes/#PermitRootLogin yes/g' /etc/ssh/sshd_config
sed -i 's/PasswordAuthentication yes/PasswordAuthentication no/g' /etc/ssh/sshd_config
mkdir -pv /root/.ssh
touch ~/.ssh/authorized_keys
cat > ~/.ssh/authorized_keys <<EOF
ssh-rsa AAAAB3NzaC1yc2EAAAABJQAAAIB+vc3h4TyVkTjrrjWHNtahkdyrSIihkPkC8bQYCDhfpls/4Doyos83G0/5u+Wq6RXbWuxsRBq/cJ+0hU7S4i8KUYRbaPzg/3UwvI5fmzk7FV5il0C/FII0Bqv4rLHyvGxQSi9jm3/S8zeBztMOKmOmxvhY3U0b5Xw1S2F+14bgnw== cootos.com
EOF
/etc/init.d/sshd restart
yum install -y make autoconf automake curl-devel gcc gcc-c++ gtk+-devel zlib-devel pcre-devel gd gettext gettext-devel kernel keyutils patch perl kernel-headers compat* mpfr cpp glibc libgomp libstdc++-devel ppl cloog-ppl keyutils-libs-devel libcom_err-devel libsepol-devel libselinux-devel krb5-devel libXpm* freetype freetype-devel freetype* fontconfig fontconfig-devel libjpeg* libpng* php-common php-gd ncurses* libtool* libxml2 libxml2-devel patch policycoreutils bison gnutls-utils
##############################
wget http://www.cmake.org/files/v2.8/cmake-2.8.11.1.tar.gz
tar -zxvf cmake-2.8.11.1.tar.gz
cd cmake-2.8.11.1
./bootstrap
make
make install
cd /allen
####################
tar -zxvf libtool-2.4.2.tar.gz
cd libtool-2.4.2
./configure
make
make install
cd /allen
#########################
echo -e "/usr/local/lib" > /etc/ld.so.conf.d/usr_local_lib.conf
/sbin/ldconfig
#############################
tar -zxvf zlib-1.2.8.tar.gz
cd zlib-1.2.8
./configure --prefix=/usr/local/zlib --shared
make
make install
cd /allen
#############################
tar -zxvf freetype-2.4.12.tar.gz
cd freetype-2.4.12
./configure --prefix=/usr/local/freetype
make
make install
cd /allen
#############################
tar -zxvf libmcrypt-2.5.8.tar.gz
cd libmcrypt-2.5.8
./configure
make
make install
cd /allen
#############################
tar -zxvf openssl-fips-2.0.4.tar.gz
cd openssl-fips-2.0.4
./config --openssldir=/usr/local/ssl
make
make install
cd /allen
#############################
rm -rf openssl-fips-2.0.4
tar -zxvf openssl-fips-2.0.4.tar.gz
cd openssl-fips-2.0.4
./config shared --openssldir=/usr/local/ssl
make
make install
cd /allen
#############################
tar -zxvf openssl-1.0.1e.tar.gz
cd openssl-1.0.1e
./config --openssldir=/usr/local/ssl
make
make install
cd /allen
#############################
rm -rf openssl-1.0.1e
tar -zxvf openssl-1.0.1e.tar.gz
cd openssl-1.0.1e
./config shared --openssldir=/usr/local/ssl
make
make install
rm -rf /usr/bin/openssl
ln -s /usr/local/ssl/bin/openssl /usr/bin/openssl
cd /allen
#############################
echo -e "/usr/local/ssl/lib" > /etc/ld.so.conf.d/usr_local_ssl.conf
/sbin/ldconfig
#############################
tar -zxvf mhash-0.9.9.9.tar.gz
cd mhash-0.9.9.9
./configure
make
make install
cd /allen
#############################
tar -zxvf pcre-8.32.tar.gz
cd pcre-8.32
./configure --prefix=/usr/local/pcre --enable-utf8
make
make install
cd /allen
#####mysql###
groupadd mysql
useradd -g mysql mysql -s /bin/false
mkdir -p /data/mysql
mkdir -p /tmp
chown -R mysql:mysql /data/mysql
chown -R mysql:mysql /tmp
mkdir -p /usr/local/mysql
tar -zxvf mysql-5.6.11.tar.gz
cd mysql-5.6.11
cmake . -DCMAKE_INSTALL_PREFIX=/usr/local/mysql \
-DMYSQL_DATADIR=/data/mysql \
-DMYSQL_UNIX_ADDR=/data/mysql/mysql.sock \
-DDEFAULT_CHARSET=utf8 \
-DDEFAULT_COLLATION=utf8_general_ci \
-DWITH_MyISAM_STORAGE_ENGINE=1 \
-DWITH_INNOBASE_STORAGE_ENGINE=1 \
-DWITH_MEMORY_STORAGE_ENGINE=1 \
-DWITH_ARCHIVE_STORAGE_ENGINE=1 \
-DWITH_BLACKHOLE_STORAGE_ENGINE=1 \
-DWITH_PERFSCHEMA_STORAGE_ENGINE=1 \
-DSYSCONFDIR=/etc \
-DENABLE_DOWNLOADS=1
make
make install
ln -s /data/mysql /var/lib/mysql
rm -rf /etc/my.cnf
ln -s /usr/local/mysql/my.cnf /etc/my.cnf
ln -s /usr/local/mysql/lib/mysql /usr/lib/mysql
ln -s /usr/local/mysql/include/mysql /usr/include/mysql
echo 'export PATH=$PATH:/usr/local/mysql/bin' >> /etc/profile
source /etc/profile
cd /usr/local/mysql
./scripts/mysql_install_db --user=mysql \
--basedir=/usr/local/mysql \
--datadir=/data/mysql
cp ./support-files/mysql.server /etc/rc.d/init.d/mysqld
chmod 755 /etc/rc.d/init.d/mysqld
chkconfig mysqld on
service mysqld start
cd /allen
#################
tar -zxvf apr-1.4.6.tar.gz
cd apr-1.4.6
./configure --prefix=/usr/local/apr
make
make install
cd /allen
#############################
tar -zxvf apr-iconv-1.2.1.tar.gz
cd apr-iconv-1.2.1
./configure --prefix=/usr/local/apr-iconv --with-apr=/usr/local/apr/bin/apr-1-config
make
make install
cd /allen
#############################
tar -zxvf apr-util-1.5.2.tar.gz
cd apr-util-1.5.2
./configure --prefix=/usr/local/apr-util --with-apr=/usr/local/apr/bin/apr-1-config --with-apr-iconv=/usr/local/apr-iconv/bin/apriconv --with-crypto --with-openssl=/usr/local/ssl --with-mysql=usr/local/mysql
make
make install
cd /allen
#############################
tar -zxvf httpd-2.4.4.tar.gz
cd httpd-2.4.4
./configure --prefix=/usr/local/apache2 \
--with-apr=/usr/local/apr/bin/apr-1-config \
--with-apr-util=/usr/local/apr-util/bin/apu-1-config \
--with-pcre=/usr/local/pcre/bin/pcre-config \
--with-z=/usr/local/zlib \
--with-libxml2 \
--enable-so \
--with-ssl=/usr/local/ssl \
--enable-ssl=static \
--enable-info \
--disable-version \
--enable-remoteip \
--enable-proxy \
--enable-proxy-connect \
--enable-proxy-ftp \
--enable-proxy-http \
--enable-session \
--enable-session-crypto \
--enable-session-cookie \
--enable-session-dbd \
--enable-dav \
--enable-dav-fs \
--enable-dav-lock \
--enable-rewrite \
--enable-cache \
--enable-file-cache \
--enable-cache-disk \
--enable-log-debug \
--enable-vhost-alias \
--enable-cgid \
--enable-cgi \
--enable-mime-magic
make
make install
rm -rf /etc/httpd
rm -rf /etc/rc.d/init.d/httpd
rm -rf /etc/httpd.conf
ln -s /usr/local/apache2 /etc/httpd
ln -s /usr/local/apache2/bin/httpd /usr/sbin/httpd
ln -s /usr/local/apache2/conf/httpd.conf /etc/httpd.conf
\cp -f /allen/httpd-2.4.4/build/rpm/httpd.init /etc/rc.d/init.d/httpd
chmod +x /etc/rc.d/init.d/httpd
groupadd apache
useradd -g apache apache -s /bin/false
mkdir -p /web
chmod -R 755 /web
cd /allen
\cp -f index.php /web/index.php
\cp -f luoo.html /web/luoo.html
\cp -f style.css /web/style.css
sed -i '61s/.*/pidfile=${PIDFILE-\/usr\/local\/apache2\/logs\/httpd.pid}/' /etc/rc.d/init.d/httpd
#############################
tar -zxvf re2c-0.13.5.tar.gz
cd re2c-0.13.5
./configure
make
make install
cd ..
#############################
tar -zxvf jpegsrc.v9.tar.gz
cd jpeg-9
./configure --prefix=/usr/local/jpeg9
make
make install
cd ..
#############################
tar -zxvf libpng-1.6.2.tar.gz
cd libpng-1.6.2
./configure --prefix=/usr/local/png \
--with-zlib-prefix=/usr/local/zlib
make
make install
cd ..
#############################
tar -zxvf libiconv-1.14.tar.gz
cd libiconv-1.14
./configure --prefix=/usr/local/iconv \
--with-zlib-prefix=/usr/local/zlib \
--with-libpng-prefix=/usr/local/png
make
make install
cd ..
#############################
tar -zxvf php-5.4.15.tar.gz
cd php-5.4.15
./configure --prefix=/usr/local/php5 \
--with-apxs2=/usr/local/apache2/bin/apxs \
--with-mysql=/usr/local/mysql \
--with-mysqli=/usr/local/mysql/bin/mysql_config \
--with-mysql-sock=/data/mysql/mysql.sock \
--with-pdo-mysql=/usr/local/mysql \
--enable-mbstring \
--with-mcrypt \
--with-openssl=/usr/local/ssl \
--with-freetype-dir=/usr/local/freetype \
--with-jpeg-dir=/usr/local/jpeg9 \
--with-png-dir=/usr/local/png \
--with-zlib-dir=/usr/local/zlib \
--with-libxml-dir=/usr \
--enable-xml \
--with-mhash \
--enable-gd-native-ttf \
--enable-pcntl \
--enable-shmop \
--with-openssl-dir=/usr/local/ssl \
--enable-soap \
--with-libxml-dir=/usr \
--enable-sockets \
--enable-sysvmsg \
--enable-sysvsem \
--enable-sysvshm \
--with-xmlrpc \
--with-libxml-dir=/usr \
--with-iconv-dir=/usr/local/iconv \
--enable-zip \
--with-zlib-dir=/usr/local/zlib \
--with-pcre-dir=/usr/local/pcre/bin/pcre-config \
--enable-mysqlnd \
--with-zlib-dir=/usr/local/zlib \
--enable-safe-mode \
--with-config-file-path=/etc
make
make install
\cp -f php.ini-production /etc/php.ini
cd ..
#############################
sed -i '919s/.*/date.timezone = PRC/' /etc/php.ini
sed -i '375s/.*/expose_php = Off/' /etc/php.ini
sed -i '211s/.*/short_open_tag = ON/' /etc/php.ini
#############################
sed -i '84s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '85s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '86s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '87s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '88s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '89s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '104s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '107s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '112s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '122s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '126s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '127s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '133s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '136s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '137s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '138s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '139s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '140s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '141s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '148s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i 's/ServerAdmin you@example.com/ServerAdmin admin@cootos.com/g' /usr/local/apache2/conf/httpd.conf
sed -i 's/#ServerName www.example.com:80/ServerName 127.0.0.1:80/g' /usr/local/apache2/conf/httpd.conf
sed -i '229s/.*/Options FollowSymLinks/' /usr/local/apache2/conf/httpd.conf
sed -i '236s/.*/AllowOverride All/' /usr/local/apache2/conf/httpd.conf
sed -i '249s/.*/DirectoryIndex index.html index.php/' /usr/local/apache2/conf/httpd.conf
sed -i '215s/.*/DocumentRoot "\/web"/' /usr/local/apache2/conf/httpd.conf
sed -i '216s/.*/<Directory "\/web"> /' /usr/local/apache2/conf/httpd.conf
sed -i '482s/^#//' /usr/local/apache2/conf/httpd.conf
sed -i '86s/.*/DocumentRoot "\/web"/' /usr/local/apache2/conf/extra/httpd-ssl.conf
sed -i '87s/.*/ServerName 127.0.0.1:443/' /usr/local/apache2/conf/extra/httpd-ssl.conf
sed -i '88s/.*/ServerAdmin cootosvpn@gmail.com/' /usr/local/apache2/conf/extra/httpd-ssl.conf
#############################
sed -i '149aAddType application\/x-httpd-php .php .phtml' /usr/local/apache2/conf/httpd.conf
sed -i '149aAddType application\/x-httpd-php-source .phps' /usr/local/apache2/conf/httpd.conf
