###MySQL 数据库备份和恢复
CentOS下MySQL数据库默认目录：
```bash
/var/lib/mysql
```
备份radius数据库：
```bash
cd /var/lib/mysql/
tar -cvf /allen/radius.tar radius
```
将整个`/var/lib/mysql/radius` 目录下的文件全部打包成为`/allen/radius.tar`
```bash
tar -zcvf /allen/radius.tar.gz radius
```
将整个`/var/lib/mysql/radius` 目录下的文件全部以gzip压缩打包成为`/allen/radius.tar.gz`
```bash
tar -jcvf /allen/radius.tar.bz2 radius
```
将整个`/var/lib/mysql/radius` 目录下的文件全部以bzip2压缩打包成为`/allen/radius.tar.bz2`
```bash
mkdir -pv /allen
cd /var/lib/mysql/
tar -zcvf /allen/radius.tar.gz radius
cd /allen
tar -zxvpf radius.tar.gz -C /var/lib/mysql
```
备份phpmyadmin数据库：
```bash
mkdir -pv /allen
cd /var/lib/mysql
tar -zcvf /allen/phpmyadmin.tar.gz phpmyadmin
```
还原phpmyadmin数据库
```bash
cd /allen
tar -zxvpf phpmyadmin.tar.gz -C /var/lib/mysql
```
保留原文件属性，解压到`/var/lib/mysql`目录。
```bash
mkdir -pv /allen
cd /var/lib/mysql
tar -zcvf /allen/phpmyadmin.tar.gz phpmyadmin
cd /allen
tar -zxvpf phpmyadmin.tar.gz -C /var/lib/mysql
```
