#iphone验证服务器
恢复iphone的时候，提示3014错误。			
`ping gs.apple.com`发现ping不通，用美国服务器ping通过，得到如下IP。 			
修改`%windir%\System32\drivers\etc`目录下的`hosts文件`
```text
%windir%\System32\drivers\etc
```
添加如下内容
```text
17.151.36.30 	gs.apple.com
```
itunes下载的升级文件保存在
```text
C:\Users\用户名\AppData\Roaming\Apple Computer\iTunes\iPhone Software Updates
```