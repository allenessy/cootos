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

    符号       含义          类型      示例
    -------------------------------------------
    ==         等于          比较     $x == $y
    !=         不等于        比较     $x != $y
    <          小于          比较     $x <  $y
    >          大于          比较     $x >  $y
    <=         小于或等于    比较     $x <= $y
    >=         大于或等于    比较     $x >= $y
    !          非            逻辑     !$x
    &&         与            逻辑     $x && $y
    AND        与            逻辑     $x and $y
    ||         或            逻辑     $x || $y
    OR         或            逻辑     $x or $y
    XOR        异或          逻辑     $x XOR $y

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

