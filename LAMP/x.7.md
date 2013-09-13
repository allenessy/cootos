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
实例：
```bash
#!/bin/sh
ip=
ip1=
ip2=
ip3=
netmask=
gateway=

cat >>/etc/sysconfig/network-scripts/ifcfg-eth0:1<<EOF
DEVICE=eth0:1
BOOTPROTO=static
IPADDR=$ip1
NETMASK=$netmask
GATEWAY=$gateway
onboot=YES
EOF

cat >>/etc/sysconfig/network-scripts/ifcfg-eth0:2<<EOF
DEVICE=eth0:2
BOOTPROTO=static
IPADDR=$ip2
NETMASK=$netmask
GATEWAY=$gateway
onboot=YES
EOF

cat >>/etc/sysconfig/network-scripts/ifcfg-eth0:3<<EOF
DEVICE=eth0:3
BOOTPROTO=static
IPADDR=$ip3
NETMASK=$netmask
GATEWAY=$gateway
onboot=YES
EOF

service network restart
```
