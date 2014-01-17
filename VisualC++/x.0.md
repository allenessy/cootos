#boost库
下载地址: [http://www.boost.org/](http://www.boost.org/)		
下载最新版本1.55后，解压后。放到指定目录结构：
```text
D:\IS_lib\boost_1_55_0			//所有文件都在里面
D:\IS_lib\boost_1_55_0\boost 	//boost文件夹
```
打开命令提示符:
```bat
D:
cd D:\IS_lib\boost_1_55_0
bootstrap.bat
```
设置环境变量
```bat
set MSVCDIR="C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC"
bjam --with-regex link=static link=shared variant=debug variant=release toolset=msvc
```
`D:\IS_lib\boost_1_55_0\stage\lib`目录下就生成了相应的库文件
```text
-with-regex 			只编译regex库，如果需要完全编译boost,就把--with-regex删除掉
link=static|shared 		表示编译静态链接库或动态链接库
variant=debug|release 	表示编译调试版或运行版
toolset=msvc 			表示使用msvc编译器
```
编译后的文件在`D:\IS_lib\boost_1_55_0\stage\lib`中，名称的含义
```text
名称中包含 		说明
lib 			static版
				shared版，不添加lib
-gd 			debug版
				release版，不添加-gd
```
