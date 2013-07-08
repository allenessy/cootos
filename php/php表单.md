###创建html表单
html表单是使用form标签和多种用于获取输出的元素创建的。如下：

    <form action="script.php" method="post">
    </form>

就php而言，form标签最重要的属性是`actioon`，它指定将把表单数据发送到哪个页面。表单的`method`属性指定如何把数据发送到处理页面。两个选项（`get`和`post`）

实例：

    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" lang="zh-CN">
    <head profile="http://gmpg.org/xfn/11">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>落网音乐</title>
    </head>
    <body>
    <form action="form.php" method="post">
    <fieldset><legend>用户注册</legend>
    <p><label>用户名：<input type="text" name="name" /></label></p>
    <p><label>密码：<input type="password" name="password" /></label></p>
    <p><label for="gender">性别：</label><input type="radio" name="gender" value="1" />男
    <input type="radio" name="gender" value="0" />女</p>
    <p><label>年龄：
    <select name="age">
        <option value="0-29">30岁以下</option>
    	<option value="30-60">30-60岁</option>
    	<option value="60+">60岁以上</option>
    </select></label></p>
    <p><input type="submit" name="submit" value="注册" /></p>
    </fieldset>
    </form>
    </body>
    </html>

你也可以为HTML表单标签制定一种字符编码：

    <form accept-charset="utf-8">

处理HTML表单： form.php

    $name=$_POST['name'];
    $password=$_POST['password'];
    $gender=$_POST['gender'];
    $age=$_POST['age'];
    //接收并打印出输入到HTML表单中的信息
    echo $name . '<br/>' . $password . '<br/>' . $gender . '<br/>' . $age;

