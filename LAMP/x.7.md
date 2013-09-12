###centos 单网卡 多IP
```bash
vi /etc/sysconfig/network-scripts/ifcfg-eth0:0
```
```bash
# XenSystem Ethernet
DEVICE=eth0:0
BOOTPROTO=static
IPADDR=192.168.0.3
NETMASK=255.255.255.0
GATEWAY=192.168.0.1
onboot=YES
```
