###Centos下系统时间和时区的修改和设置
一般购买的VPS或独立服务器时区可能是美国当地时间，不是中国的时间，使用定时任务或其它项目的时候，系统时间很重要，合理的时区和时间设置可以保证日后维护和使用的方便。
#####一、修正时区
```bash
rm -rf /etc/localtime    #删除当前默认时区
ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
#复制替换默认时区为上海
```
#####二、手动修正时间
```bash
date -s '09:16:00 2013-01-21'
```
使用“date”命令，修改时间和日期为2013年1月21日，时间是上午9点16分0秒。

#####三、时间自动同步和校正
```bash
yum install -y ntp        #安装时间同步服务（组件）
ntpdate us.pool.ntp.org   #设置同步服务器
date                      #查看当前时间
```
部分系统已经安装了NTP服务，系统会根据当前记录的时区（第一步操作）自动连接ntp服务器校正时间。

此方法适用于大部分独立服务器和虚拟化（Xen、KVM）的Linux系统，如Centos及Debian，部分OpenVZ虚拟话系统可能无法修改。部分Xen VPS请使用下面方法：

#####一、修正时间

* 1、编辑/etc/sysctl.conf
```bash
vi /etc/sysctl.conf
```
 SSH执行以上命令，在该文件底部加入以下代码。
```bash
xen.independent_wallclock = 1
```
保存并退出。

* 2、执行以下命令
```bash
sysctl -p
```
SSH执行以上命令，重新加载系统参数。

* 3、依次执行以下命令
```bash
rm -rf /etc/localtime    #删除当前默认时区
ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
```
 复制替换默认时区为上海
```bash
yum install -y ntp        #安装时间同步服务（组件）
ntpdate us.pool.ntp.org   #设置同步服务器
date                      #查看时间（时区）是否生效
```
SSH中依次逐行执行以上命令，即可替换默认时区，更新为上海时间。若执行“date”后时间恢复正常，则表示修改成功。
#####二、自动同步时间

为了保证时间的准确性和或防止VPS和母机时间再一次同步，请设置开机时自动同步最新的时间。
* 1、查询ntpdate组件所在位置
```bash
which ntpdate
```
 SSH执行以上命令，查询ntpdate组件所在路径。（可跳过）
* 2、添加开机自动启动项
 - （1）修改/etc/rc.local文件
```bash
vi /etc/rc.local
```
 SSH执行以上命令。
 - （2）在适当位置加上以下命令
```bash
/usr/sbin/ntpdate us.pool.ntp.org
```
北京时间国内NTP服务器:
```bash
/usr/sbin/ntpdate ntp.sjtu.edu.cn       //上海交通大学网络中心NTP服务器地址
```

#####自动校对北京时间shell脚本
```bash
#/bin/sh
#修改CentOS时间为北京时间

#删除当前默认时区
rm -rf /etc/localtime    

#复制替换默认时区为上海
ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

#安装时间同步服务（组件）
yum install -y ntp

#设置同步服务器
ntpdate us.pool.ntp.org

#查看当前时间
date

#添加开机自动启动校队时间
echo "/usr/sbin/ntpdate us.pool.ntp.org" >>/etc/rc.local
```
