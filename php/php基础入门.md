####第一个php程序

    <?php
    echo 'hello world';
    ?>

有些浏览器显示乱码，修改为:

    <?php
    //设置为UTF-8，防止中文乱码
    header("Content-Type: text/html; charset=utf-8");
    echo 'hello world';
    echo "<br>";
    print "你好，世界!";
    ?>

###基础知识
PHP 文件或 PHP 代码段以`<?php`开始        
PHP 文件或 PHP 代码段以`?>`结束，中间为php代码。 如果是独立的PHP文件，也就是说里面全是PHP代码，不是嵌入在html中的PHP文件，可以没有结束符。如：     

    <?php
    echo '你好';

####  ;  分号
每一个指令集以 `; `符号结束 PHP 中的每个代码行都必须以分号结束。分号是一种分隔符，用于把指令集区分开来。 

    echo 'hello world';

####  echo  print
echo、print 是 PHP 的内置函数，用于输出1个或多个字符串。  

    echo '你好，世界';
    print '你好，世界';

将一些html代码发送到web浏览器:

    echo '<p>第一行,<br/>第二行.</p>';

注：`<br/>`是html页面中的换行符，`\n `是php中的为了使html文件的源码更方便查看和美观的换行符。
#### 注释    
PHP支持3种注释类型。第一种使用磅即编号符号 `#`  ,第二种使用两个斜杠 `//`  ,第三个风格允许注释多行,注释内容放在 `/* `与` */` 中间。

    #单行注释
    
    //单行注释
    
    /*
     * 多行注释
    */

####变量
变量的名称，必须以美元符号 `$` 开头，例如： `$name`   
变量名称可以包含`字母`、`数字`和`下划线`的组合，例如`$my_repo1`         
美元符号之后的第一个字符必须是`字母`或`下划线`（不能是数字）
php中的变量名称是区分大小写的，这是一个重要的规则。这意味着`$name`和`$Name`是截然不同的变量。

    $v1 = 'hello world';
    $v2 = 17;

打印变量：

    print $name;
    print "$name";

####字符串
#####连接运算符  .  
连接运算符 `.`用于把两个字符串值连接起来。 . 号用于连接字符串。           
要把两个变量连接在一起，请使用这个点运算符 `.` ：

    $text1 = 'hello';
    $text2 = 'world';
    echo $text1 . " " .$text2;

为了分隔这两个变量，我们在 $text1 与 $text2 之间插入了一个空格，使用了两个两件运算符。
####strlen() 函数
strlen() 函数用于计算字符串的长度。

    echo strlen("hello world!");

####strpos() 函数
strpos() 函数用于在字符串内检索一段字符串或一个字符。          
如果在字符串中找到匹配，该函数会返回第一个匹配的位置。如果未找到匹配，则返回 `FALSE`。          
让我们试一下，是不是能在字符串中找到子字符串 `world`：

	echo strpos("Hello world!","world");

以上代码的输出是：`6`       
正如您看到的，在我们的字符串中，字符串 `world` 的位置是 `6`。返回 `6` 而不是 `7`，是由于字符串中的首个位置的 `0`，而不是 `1`。

###数组
数组能够在单独的变量名中存储一个或多个值。

数组中的元素都有自己的 ID，因此可以方便地访问它们。
有三种数组类型：
索引数组
带有数字 ID 键的数组
关联数组
数组中的每个 ID 键关联一个值
多维数组
包含一个或多个数组的数组
####索引数组
索引数组存储的每个元素都带有一个数字 ID 键。
可以使用不同的方法来创建索引数组：
例子 1
在这个例子中，会自动分配 ID 键：

	$names = array("Peter","Quagmire","Joe");

例子 2
在这个例子中，我们人工分配的 ID 键：

	$names[0] = "Peter";
	$names[1] = "Quagmire";
	$names[2] = "Joe";

可以在脚本中使用这些 ID 键：

	echo $names[1] . " and " . $names[2] . " are ". $names[0] . "'s neighbors";

###关联数组
关联数组，它的每个 ID 键都关联一个值。
在存储有关具体命名的值的数据时，使用数值数组不是最好的做法。
通过关联数组，我们可以把值作为键，并向它们赋值。
例子 1
在本例中，我们使用一个数组把年龄分配给不同的人：

	$ages = array("Peter"=>32, "Quagmire"=>30, "Joe"=>34);

例子 2
本例与例子 1 相同，不过展示了另一种创建数组的方法：

	$ages['Peter'] = "32";
	$ages['Quagmire'] = "30";
	$ages['Joe'] = "34";

可以在脚本中使用 ID 键：

	echo "Peter is " . $ages['Peter'] . " years old.";

###多维数组
在多维数组中，主数组中的每个元素也是一个数组。在子数组中的每个元素也可以是数组，以此类推。

例子 1
在本例中，我们创建了一个带有自动分配的 ID 键的多维数组：

	$families = array
	(
	  "Griffin"=>array
 	 (
 	 "Peter",
 	 "Lois",
 	 "Megan"
 	 ),
 	 "Quagmire"=>array
 	 (
 	 "Glenn"
 	 ),
 	 "Brown"=>array
  	(
  	"Cleveland",
 	 "Loretta",
 	 "Junior"
	  )
	);
	print_r($families);

例子 2
让我们试着显示上面的数组中的一个单一的值：

	$families['Griffin'][2]


