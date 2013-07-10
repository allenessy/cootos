关机命令

    sudo shutdown -h now

重启Ubuntu系统

    sudo reboot

设置IP地址

    sudo /etc/network/interfaces

如果配置动态获取ip，则在上述文件中加入以下内容：

    auto eth0
    iface eth0 inet dhcp

如果配置静态ip，则添加如下内容：

    auto eth0
    iface eth0 inet static
    address 192.168.33.201
    netmask 255.255.255.0
    gateway 192.168.33.1

要是配置生效，需要重启网卡：

    ifconfig eth0 down
    ifconfig eth0 up

若还有没有配置成功，则需重启下网络服务

    /etc/init.d/networking restart

ubuntu 的dns服务器信息，放在 `/etc/resolv.conf`中,
添加dns服务器地址，如`8.8.8.8`,则在上述文件中加入

    nameserver  8.8.8.8
