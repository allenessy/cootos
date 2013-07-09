故障背景： 
在vmware workstation中了完全克隆了一个已经存在的centos的虚拟机，启动之后发现网卡没有启动。于是重启一下network服务，发现提示错误信息“Device eth0 does not seem to be present, delaying initialization.” 
 
故障产生的原因： 
 
由于克隆虚拟机，vmware只是修改了虚拟机的名字等信息，并没有修改虚拟硬盘中的任何信息，导致克隆后网卡的MAC地址和操作系统中记录的mac地址不符，导致eth0启动不起来。操作系统记录了一个新网卡的添加，新网卡的名字eth1，mac地址就是vmware分配给的新的mac地址 
 
解决方法： 
 
一、

修改`vi /etc/udev/rules.d/70-persistent-net.rules` 文件 
删除掉 关于 eth0 的信息。修改 第二条 eth1 的网卡的名字为 eth0. 
 
修改 `/etc/sysconfig/network-scripts/ifcfg-eth0` 中mac地址为 `/etc/udev/rules.d/70-persistent-net.rules` 修改后的eth0的    mac地址。 
reboot 重启服务器。


二、

    cat /etc/udev/rules.d/70-persistent-net.rules 

    ... ....
    # PCI device 0x8086:0x100f (e1000) SUBSYSTEM=="net", ACTION=="add", DRIVERS=="?*", 
    ATTR{address}=="00:0c:29:79:c8:b9", ATTR{type}=="1", KERNEL=="eth*", NAME="eth1" 

70-persistent-net.rules里面存放着centos系统认到的网卡信息和系统文件eth*的绑定。照着修改就行了，可以看到MAC信息，网卡名称eth1。

    vi /etc/sysconfig/network-scripts/ifcfg-eth1
