用Notepad++ 打开*.vmx 文件
找到：

    ethernet0.present = "TRUE"

在它下面添加一行：

    ethernet0.virtualDev = "e1000"

保存退出，好了我们去看看ChromeOS-Vanilla，是否能登陆了。
