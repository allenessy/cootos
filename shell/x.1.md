###-bash: ./one.sh: Permission denied
```bash
./one.sh
```
执行上面的命令的时候提示下面的错误：
```text
-bash: ./one.sh: Permission denied
```
权限问题,用下面的命令，解决该问题。
```bash
chmod +x one.sh
```
在执行该命令，正常。