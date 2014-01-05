###Found a swap file by the name
当我在linux下用vi打开one.sh文件时，出现如下提示:
```text
E325: ATTENTION
Found a swap file by the name ".one.sh.swp"
          owned by: root   dated: Sun Jan  5 22:38:18 2014
         file name: /cis/one.sh
          modified: YES
         user name: root   host name: localhost.localdomain
        process ID: 9978
While opening file "one.sh"
             dated: Sun Jan  5 22:37:46 2014

(1) Another program may be editing the same file.
    If this is the case, be careful not to end up with two
    different instances of the same file when making changes.
    Quit, or continue with caution.

(2) An edit session for this file crashed.
    If this is the case, use ":recover" or "vim -r one.sh"
    to recover the changes (see ":help recovery").
    If you did this already, delete the swap file ".one.sh.swp"
    to avoid this message.
"one.sh" 4L, 49C
Press ENTER or type command to continue
```
原因是我之前又一次使用vi操作one.sh文件时，出现了异常中断，所以在当前目录下产生了一个.one.sh.swp文件 			
但是我使用ls命令查看该目录下，却没有发现这个文件，后来使用ls -a命令查看才知道.one.sh.swp是一个隐藏文件。 			
注: 以.开头的文件就是隐藏文件
```bash
rm -rf .one.sh.swp
```
当我把该隐藏文件删除后再打开就没有上面的警告了.