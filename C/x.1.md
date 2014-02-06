###gcc编译的时候出错信息
gcc: error trying to exec 'as': execvp: No such file or directory

```text
error: ‘for’ loop initial declarations are only allowed in C99 mode
use option -std=c99 or -std=gnu99 to compile your code
```
出现以上错误信息，是因为我直接在for(里面声明赋值变量),编译的时候使用如下命令即可。
```bash
gcc -std=c99 -o one one.c
```
gcc下的语言规范设置
```text
-std=iso9899:1990     来指定完全按照c89规范，而禁止gcc对c语言的扩展
-ansi                 来指定完全按照c89规范，而禁止gcc对c语言的扩展
-std=c89              来指定完全按照c89规范，而禁止gcc对c语言的扩展
-std=iso9899:199409   使用C95规范
-std=c99              使用C99规范
-std=iso9899:1999     使用C99规范
-std=gnu89            使用c89规范加上gcc自己的扩展(目前默认)
-std=gnu99            使用c99规范加上gcc自己的扩展
```