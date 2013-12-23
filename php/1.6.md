php用于创建条件语句的3个主要术语是：if、else和elseif(它也可以写着两个单词 `else if`)。    
实例1:

    if (条件){
     //内容
    }

实例2:

    if (条件){
      //内容
    } else {
      //内容
    }

实例3:

    if (条件){
      //内容
    } elseif(条件2) {
      //内容
    } else {
      //内容
    }

如果条件为真，则执行其下面的花括号`{}` 中的代码。如果条件不为真，PHP将继续往下执行。如果有第二个条件（在`elseif`之后），则检查其是否为真。这个过程将继续（可以根据需要使用多个`elseif`字句）直至PHP遇到`else`,此时将自动执行它，或者如果没有`else`,php将执行到条件语句终止为止。
          
PHP中条件为真的情况有许多种。下面是常见的一些。         
`$var` 如果$var具有非0值、空字符串、FALSE或NULL，则条件为真；            
`isset($var` 如果$var具有不同于NULL的任何值，包括0、FALSE或空字符串，则条件为真；             
`TRUE`、`true`、`True`等。    

比较和逻辑运算符：
<table>
<tr><td>符号</td><td>含义</td><td>类型</td><td>示例</td></tr>
<tr><td>==</td><td>等于</td><td>比较</td><td>$x == $y</td></tr>
<tr><td>!=</td><td>不等于</td><td>比较</td><td>$x != $y</td></tr>
<tr><td>&lt;</td><td>小于</td><td>比较</td><td>$x &lt;  $y</td></tr>
<tr><td>&gt;</td><td>大于</td><td>比较</td><td>$x &gt;  $y</td></tr>
<tr><td>&lt;=</td><td>小于或等于</td><td>比较</td><td>$x &lt;= $y</td></tr>
<tr><td>&gt;=</td><td>大于或等于</td><td>比较</td><td>$x &gt;= $y</td></tr>
<tr><td>!</td><td>非</td><td>逻辑</td><td>!$x</td></tr>
<tr><td>&&</td><td>与</td><td>逻辑</td><td>$x && $y</td></tr>
<tr><td>AND</td><td>与</td><td>逻辑</td><td>$x and $y</td></tr>
<tr><td>||</td><td>或</td><td>逻辑</td><td>$x || $y</td></tr>
<tr><td>OR</td><td>或</td><td>逻辑</td><td>$x or $y</td></tr>
<tr><td>XOR</td><td>异或</td><td>逻辑</td><td>$x XOR $y</td></tr>
</table>
使用两个条件语句验证性别单选按钮。

    if (isset($_POST['gender'])){
        $gender=$_POST['gender'];
    }else{
    	$gender=NULL;
    }

判断值语句：

    if($gender == '0') {
        echo '<p><b>Good day,Sir!</b></p>';
    }elseif($gender == '1') {
    	echo '<p><b>Good day,Madam!</b></p>';
    }else{
    	echo '<p><b>您还没有选择性别！</b></p>';
    }

###switch
switch,最适合代替较长的if-elseif-else条件语句。switch语法是：

    switch($variable){
        case 'value1':
                //Do this
                break;
        case 'value2':
                //Do this
                break;
        default:
                //Do this then
                break;
    }

switch条件语句将$variable的值与不同的case作比较，当它发现一个匹配时，就会执行其后的代码，直至遇到break,如果没有发现匹配，则会执行default

###for 和 while 循环
我们在访问数组中的每个元素时，已经使用过一种循环，即 foreach 下面你将使用的两种循环类型是for和while   
while循环看起来如下所示：

    while (condition){
		//Do something.
	}

只要循环的条件(condition)为真，就会执行循环。一旦条件为假，就会停止循环。如果条件永远不会为真，就永远不会执行循环。

for循环具有更复杂的语法：

	for (initial expression;condition;closing expression){
			//Do something.
	}

while循环的流程图表示：
	
						  |
				          ↓
			 ------------条件<--------
			|             |           |
			|	          |           |
			|	          ↓           |
			|	如果为TRUE,就执行它---
			|	
		    |
			|
			↓
    一旦条件为FALSE，就退出循环			

在第一次执行循环时，会运行初始化表达式(initial expression).然后检查条件，如果条件为真，就执行循环的内容。执行之后，将会运行结束表达式，并再次检查条件。这个过程会继续下去，直到条件为假。

	for ($i = i;$i <= 10;$i++){
			echo $i;
	}

流程图：

						 for
						  |
						  ↓
					 初始表达式
						  |
				          ↓
			 ------------条件<--------
			|             |           |
			|	          |       表达式之后
			|	          ↓           |
			|	如果为TRUE,就执行它---
			|	
		    |
			|
			↓
    一旦条件为FALSE，就退出循环

使用循环：

	echo '<select name="day">';
	for($day=1;$day<=31;$day++){
		echo "<option value=\"$day\">$day</option>";
	}
	echo '</select>';


