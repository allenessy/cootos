#!/bin/sh
#hostname="127.0.0.1"
#post="3306"
#设置MySQL用户名
username="root"
#设置MySQL密码
password="password"
dbname="radius"

#mysql_conn="mysql -u${username} -p${password}"
#echo ${mysql_conn}
create_db_sql="create database IF NOT EXISTS ${dbname}"
mysql -u${username} -p${password} -e "${create_db_sql}"
echo "mysql -u${username} -p${password} -e \"${create_db_sql}\""

yum -y install gcc gcc-c++ make cmake automake autoconf unzip gmp gmp-devel flex bison perl iptables ppp freeradius*

mysql -u${username} -p${password} ${dbname} < /etc/raddb/sql/mysql/schema.sql
mysql -u${username} -p${password} ${dbname} < /etc/raddb/sql/mysql/nas.sql
mysql -u${username} -p${password} ${dbname} < /etc/raddb/sql/mysql/ippool.sql
mysql -u${username} -p${password} ${dbname} < /etc/raddb/sql/mysql/wimax.sql
mysql -u${username} -p${password} ${dbname} < /etc/raddb/sql/mysql/cui.sql

insert_sql01="INSERT INTO radgroupreply (groupname,attribute,op,VALUE) VALUES ('user','Auth-Type',':=','Local');"
insert_sql02="INSERT INTO radgroupreply (groupname,attribute,op,VALUE) VALUES ('user','Service-Type',':=','Framed-User');"
insert_sql03="INSERT INTO radgroupreply (groupname,attribute,op,VALUE) VALUES ('user','Framed-IP-Address',':=','255.255.255.255');"
insert_sql04="INSERT INTO radgroupreply (groupname,attribute,op,VALUE) VALUES ('user','Framed-IP-Netmask',':=','255.255.255.0');"
insert_sql05="INSERT INTO radgroupreply (groupname,attribute,op,VALUE) VALUES ('user','Acct-Interim-Interval',':=','600');"
insert_sql06="INSERT INTO radgroupreply (groupname,attribute,op,VALUE) VALUES ('user','Max-Monthly-Traffic',':=','536870912000');"
insert_sql07="INSERT INTO radgroupcheck (groupname,attribute,op,VALUE) VALUES ('user','Simultaneous-Use',':=','1');"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql01}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql02}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql03}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql04}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql05}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql06}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql07}"

echo "ATTRIBUTE Max-Monthly-Traffic 3003 integer">>/etc/raddb/dictionary
echo "ATTRIBUTE Monthly-Traffic-Limit 3004 integer">>/etc/raddb/dictionary

insert_sql08="INSERT INTO radcheck (username,attribute,op,VALUE) VALUES ('test','Cleartext-Password',':=','test');"
insert_sql09="INSERT INTO radusergroup (username,groupname) VALUES ('test','user');"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql08}"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql09}"

\cp -f /etc/raddb/radiusd.conf  /etc/raddb/radiusd.conf_bak
sed -i '700s/#//' /etc/raddb/radiusd.conf
sed -i '712s/#//' /etc/raddb/radiusd.conf
sed -i '717s/#//' /etc/raddb/radiusd.conf

\cp -f /etc/raddb/sql.conf /etc/raddb/sql.conf_bak
#设置MySQL用户
sed -i 's/login = "radius"/login = "root"/g' /etc/raddb/sql.conf
#设置MySQL密码
sed -i 's/password = "radpass"/password = "password"/g' /etc/raddb/sql.conf
sed -i '100s/#//' /etc/raddb/sql.conf

\cp -f /etc/raddb/sites-available/default /etc/raddb/sites-available/default_bak
sed -i '177s/#//' /etc/raddb/sites-available/default
sed -i '406s/#//' /etc/raddb/sites-available/default
sed -i '426s/#//' /etc/raddb/sites-available/default
sed -i '454s/#//' /etc/raddb/sites-available/default
sed -i '475s/#//' /etc/raddb/sites-available/default
sed -i '481s/#//' /etc/raddb/sites-available/default
sed -i '563s/#//' /etc/raddb/sites-available/default
sed -i 's/files/#files/g' /etc/raddb/sites-available/default
sed -i 's/unix/#unix/g' /etc/raddb/sites-available/default
sed -i 's/radutmp/#radutmp/g' /etc/raddb/sites-available/default

\cp -f /etc/raddb/sites-enabled/inner-tunnel /etc/raddb/sites-enabled/inner-tunnel_bak
sed -i '131s/#//' /etc/raddb/sites-enabled/inner-tunnel
sed -i '255s/#//' /etc/raddb/sites-enabled/inner-tunnel
sed -i '277s/#//' /etc/raddb/sites-enabled/inner-tunnel
sed -i '283s/#//' /etc/raddb/sites-enabled/inner-tunnel
sed -i '301s/#//' /etc/raddb/sites-enabled/inner-tunnel
sed -i 's/files/#files/g' /etc/raddb/sites-enabled/inner-tunnel
sed -i 's/unix/#unix/g' /etc/raddb/sites-enabled/inner-tunnel
sed -i 's/radutmp/#radutmp/g' /etc/raddb/sites-enabled/inner-tunnel


insert_sql10="INSERT INTO nas (nasname,shortname,secret) VALUES ('127.0.0.1','localhost','testing123');"
mysql -u${username} -p${password} ${dbname} -e "${insert_sql10}"

\cp -f /etc/raddb/sql/mysql/dialup.conf /etc/raddb/sql/mysql/dialup.conf_bak
sed -i '279s/#//' /etc/raddb/sql/mysql/dialup.conf
sed -i '280s/#//' /etc/raddb/sql/mysql/dialup.conf
sed -i '281s/#//' /etc/raddb/sql/mysql/dialup.conf
sed -i '282s/#//' /etc/raddb/sql/mysql/dialup.conf

\cp -f /etc/raddb/sql/mysql/counter.conf /etc/raddb/sql/mysql/counter.conf_bak
echo "sqlcounter monthlytrafficcounter {">>/etc/raddb/sql/mysql/counter.conf
echo "counter-name = Monthly-Traffic">>/etc/raddb/sql/mysql/counter.conf
echo "check-name = Max-Monthly-Traffic">>/etc/raddb/sql/mysql/counter.conf
echo "reply-name = Monthly-Traffic-Limit">>/etc/raddb/sql/mysql/counter.conf
echo "sqlmod-inst = sql">>/etc/raddb/sql/mysql/counter.conf
echo "key = User-Name">>/etc/raddb/sql/mysql/counter.conf
echo "reset = monthly">>/etc/raddb/sql/mysql/counter.conf
echo "query = \"SELECT SUM(acctinputoctets + acctoutputoctets) DIV 1024 FROM radacct ">>/etc/raddb/sql/mysql/counter.conf
echo "WHERE UserName='%{%k}' AND UNIX_TIMESTAMP(AcctStartTime) > '%b'\"">>/etc/raddb/sql/mysql/counter.conf
echo "}">>/etc/raddb/sql/mysql/counter.conf

wget https://raw.github.com/allenessy/cootos/master/LAMP/dag.repo
\cp -f dag.repo /etc/yum.repos.d/dag.repo

yum -y install radiusclient-ng*
\cp -f /etc/radiusclient-ng/radiusclient.conf /etc/radiusclient-ng/radiusclient.conf_bak
sed -i '37s/localhost/localhost:1812/' /etc/radiusclient-ng/radiusclient.conf
sed -i '42s/localhost/localhost:1813/' /etc/radiusclient-ng/radiusclient.conf
sed -i '75s/^/#/' /etc/radiusclient-ng/radiusclient.conf

\cp -f /usr/share/radiusclient-ng/dictionary /usr/share/radiusclient-ng/dictionary_bak
echo "INCLUDE /usr/share/radiusclient-ng/dictionary.merit">>/usr/share/radiusclient-ng/dictionary
echo "INCLUDE /usr/share/radiusclient-ng/dictionary.microsoft">>/usr/share/radiusclient-ng/dictionary
echo "INCLUDE /usr/share/radiusclient-ng/dictionary.ascend">>/usr/share/radiusclient-ng/dictionary
echo "INCLUDE /usr/share/radiusclient-ng/dictionary.compat">>/usr/share/radiusclient-ng/dictionary
echo "INCLUDE /usr/share/radiusclient-ng/dictionary.sip">>/usr/share/radiusclient-ng/dictionary

cd /usr/share/radiusclient-ng
wget https://raw.github.com/allenessy/cootos/master/LAMP/dictionary.microsoft

\cp -f /etc/radiusclient-ng/servers /etc/radiusclient-ng/servers_bak
echo "localhost testing123">>/etc/radiusclient-ng/servers

service mysqld restart
service radiusd restart
