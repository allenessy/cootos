关机命令<br>
sudo shutdown -h now<br>
<br>
重启Ubuntu系统<br>
sudo reboot<br>
<br>
设置IP地址<br>
sudo /etc/network/interfaces<br>
<br>
如果配置动态获取ip，则在上述文件中加入以下内容：<br>
auto eth0<br>
iface eth0 inet dhcp<br>
<br>
如果配置静态ip，则添加如下内容：<br>
auto eth0<br>
iface eth0 inet static<br>
address 192.168.33.201<br>
netmask 255.255.255.0<br>
gateway 192.168.33.1<br>
<br>
要是配置生效，需要重启网卡：<br>
ifconfig eth0 down<br>
ifconfig eth0 up<br>
<br>
若还有没有配置成功，则需重启下网络服务<br>
/etc/init.d/networking restart<br>
<br>
ubuntu 的dns服务器信息，放在 /etc/resolv.conf中,<br>
添加dns服务器地址，如8.8.8.8,则在上述文件中加入<br>
nameserver  8.8.8.8<br>
