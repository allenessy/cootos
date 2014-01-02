###安装freeradius
```bash
yum -y install freeradius*
```
```bash
vi /etc/raddb/sites-available/default
```
```bash
vi /etc/raddb/sites-enabled/inner-tunnel
```
`sql`     去掉所有`sql`前面的`#`注释 				
`files`   所有`files`前面加上`#`注释 				
`radutmp` 所有`radutmp`前面加上`#`注释  				
安装设置好 freeradius后，进行测试
```bash
vi /etc/raddb/radiusd.conf
```
`$INCLUDE  sql.conf`  把前面的`#`取消掉,第700行 				
```bash
vi /etc/raddb/sql.conf
```
找到这一段修改成这样
```text
database = "mysql"
server   = "localhost"
login    = "用户名"
password = "密码"
```
`readclients = yes`		把前面的`#`取消掉,第100行
```bash
vi /etc/raddb/sql/mysql/dialup.conf
```
去掉279-282前面的#注释，打开（控制同时在线用户数）
```text
simul_count_query = "SELECT COUNT(*) \
                              FROM ${acct_table1} \
                              WHERE username = '%{SQL-User-Name}' \
                              AND acctstoptime IS NULL"
```
```text
sql_user_name = "%{%{Stripped-User-Name}:-%{%{User-Name}:-DEFAULT}}"
```
第25行前面加上#注释
```text
sql_user_name = "%{User-Name}"
```
取消第27行前面的#注释 				
#####启用流量统计
```bash
vi /etc/raddb/dictionary
```
在 字典文件 `/etc/raddb/dictionary` 末尾添加如下两行
```text
ATTRIBUTE Max-Monthly-Traffic 3003 integer
ATTRIBUTE Monthly-Traffic-Limit 3004 integer
```
```bash
vi /etc/raddb/sql/mysql/counter.conf
```
在 `/etc/raddb/sql/mysql/counter.conf` 文件末尾添加如下字段
```text
sqlcounter monthlytrafficcounter {
    counter-name = Monthly-Traffic
    check-name = Max-Monthly-Traffic
    reply-name = Monthly-Traffic-Limit
    sqlmod-inst = sql
    key = User-Name
    reset = monthly
    query = "SELECT SUM(acctinputoctets + acctoutputoctets) DIV 1024 FROM radacct \
WHERE UserName='%{%k}' AND UNIX_TIMESTAMP(AcctStartTime) > '%b'"
}
```
###数据库
```bash
mysql -uroot -p radius < /etc/raddb/sql/mysql/schema.sql      //主数据库
mysql -uroot -p radius < /etc/raddb/sql/mysql/nas.sql         //网络设备表
mysql -uroot -p radius < /etc/raddb/sql/mysql/ippool.sql
mysql -uroot -p radius < /etc/raddb/sql/mysql/wimax.sql
mysql -uroot -p radius < /etc/raddb/sql/mysql/cui.sql
```
```sql
INSERT INTO `radius`.`radgroupreply` (groupname,attribute,op,VALUE) VALUES ('user','Auth-Type',':=','Local');
INSERT INTO `radius`.`radgroupreply` (groupname,attribute,op,VALUE) VALUES ('user','Service-Type',':=','Framed-User');
INSERT INTO `radius`.`radgroupreply` (groupname,attribute,op,VALUE) VALUES ('user','Framed-IP-Address',':=','255.255.255.255');
INSERT INTO `radius`.`radgroupreply` (groupname,attribute,op,VALUE) VALUES ('user','Framed-IP-Netmask',':=','255.255.255.0');
INSERT INTO `radius`.`radgroupreply` (groupname,attribute,op,VALUE) VALUES ('user','Acct-Interim-Interval',':=','600');
INSERT INTO `radius`.`radgroupreply` (groupname,attribute,op,VALUE) VALUES ('user','Max-Monthly-Traffic',':=','536870912000');
INSERT INTO `radius`.`radgroupcheck` (groupname,attribute,op,VALUE) VALUES ('user','Simultaneous-Use',':=','1');
```
以上前四行是PPP用的参数，不用改动，acct-interim-interval是计算流量的间隔（600秒），意味着每隔10分钟记录当前流量。最后一行是每月最大流量，这里是5G（单位是字节）。

###测试
输入测试用户信息
```sql
INSERT INTO `radius`.`radcheck` (username,attribute,op,VALUE) VALUES ('test','Cleartext-Password',':=','test');
INSERT INTO `radius`.`radusergroup` (username,groupname) VALUES ('test','user');
```

在一个SSH窗口中输入：
```bash
radiusd -X
```
至到显示Read to process requests.新打开一个SSH，输入：
```bash
radtest test test localhost 0 testing123
```
提示错误信息如下：
```bash
radclient: no response from server for ID 215 socket 3
```
出错前NAS表之前的设置是：
```bash
INSERT INTO radius.nas (nasname,shortname,secret) VALUES ('127.0.0.1','localhost','testing123');
```
解决方法如下(`nasname`的值，必须是NAS的IP地址，不能用`127.0.0.1`)：
```bash
INSERT INTO radius.nas (nasname,shortname,secret) VALUES ('192.168.0.35','localhost','testing123');
```
故障解决。
```bash
rad_recv: Access-Accept packet from host #正常
```
```bash
rad_recv: Access-Request packet from host #错误信息
```
故障原因：`/etc/raddb/sql.conf`, 把`readclients = yes` 前面的`#`取消掉。第100行。意思是没有读取数据库中`nas`表的相关信息，所以造成了服务器的拒绝服务
