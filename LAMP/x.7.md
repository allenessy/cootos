###centos 单网卡 多IP
```bash
vi /etc/sysconfig/network-scripts/ifcfg-eth0
```
```bash
#--------------
IPADDR2=192.168.10.2
PREFIX2=24
GATEWAY2=192.168.0.1
#--------------
IPADDR3=192.168.10.3
PREFIX3=24
GATEWAY3=192.168.0.1
#--------------
IPADDR4=192.168.10.5
PREFIX4=24
GATEWAY4=192.168.0.1
```
