###-bash: ./one.sh: /bin/sh^M: bad interpreter: No such file or directory
原因：one.sh文件是我在Windows下面编辑好，上传到linux上面的，执行后提示下面的错误：
```text
-bash: ./one.sh: /bin/sh^M: bad interpreter: No such file or directory
```
.sh文件的格式为dos格式。而linux只能执行格式为unix格式的脚本 			
首先用vi打开该文件
```bash
vi one.sh
```
在vi命令模式中使用`:set ff`命令查看文件格式
```bash
:set ff
```
显示文件格式为dos
```text
fileformat=dos
```
修改文件格式为unix
```bash
:set ff=unix
```
再查看文件格式，已经是unix了			
或者可以直接使用dos2unix命令转换文件
```bash
dos2unix one.sh
```