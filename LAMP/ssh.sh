#!/bin/sh
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
