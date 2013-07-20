javascript弹出消息对话框

    <script type="text/javascript">alert("弹出消息对话框!");</script>

javascript输出文本

    <script type="text/javascript">document.write("输出文本");</script>

javascript引用外部脚本

    <script type ="text/javascript" src="./js/jquery.js"></script>

#####字符串（String）类型    
字符串类型使用双引号 " 或单引号 ' 括起来，下面是一些例子    

    <script type="text/javascript">
    var str1='20 ';
    var str2='岁';
    alert(str1+str2);
    </script>

如上例所示，字符串可以使用 + 符号进行连接，运行例子弹出提示框输出：       
运行该例子，弹出提示框并输出：20 岁     


#####数值（Number）类型    
数值（Number）类型包括整数和浮点数（包含小数点的数或科学记数法的数），如：     

    <script type="text/javascript">
    var str1=20;
    var str2=33.5;
    alert(str1+str2);
    </script>

运行该例子，弹出提示框并输出：运算结果为：53.5     
    
#####布尔（Boolean）类型     
布尔类型是对一个表达式结果的确定，如果该表达式成立，则结果为 true，反之则为 false。通常结合 if 语句来进行逻辑判断，如下面例子所示：    

    <script type="text/javascript">
    var x = 3;
    var y = 5;
    if ( x == y ){
        alert(  "x 等于 y" );
    }else{
    	alert(  "x 不等于 y" );
    }
    </script>

输出： x 不等于 y    
    
      
#####空值（Null）     
空值类型表示该变量或内容无任何值。例如一个表单文本输入框中无任何内容时，我们试图用 JavaScript 去获取该文本输入框元素的值时，得到的结果就是 null。     
要判断是否为空值，只需将需要比较的内容与 null 进行比较即可：    

    if( x == null ){ ... }

鉴于 Web 系统运行的特点，很多情况下可以通过给一个变量赋 null 值来清除变量的内容而不用特意去销毁该变量。   

#####未定义（Undefined）类型
变量被创建后，未给该变量赋值，该变量即为未定义类型。未定义类型有一个确定的值 undefined，因此要判断一个变量或返回结果是否为未定义类型，只需将它与 undefined 进行比较即可：

    if(  x == undefined ){ ... }

#####对象（Object）类型    
对象类型是 JavaScript 中常用的一个类型，如我们通过 document.getElementById() 获取页面元素时，得到的就是一个对象。    

    <div id="str">测试内容</div>
    <script type="text/javascript">
    x = document.getElementById("str");
    alert(x);
    </script>

弹出提示框输出：[object]，表明这是一个对象。

#####插入特殊字符
<table>
<tr><td>\'</td><td>单引号</td><td>\"</td><td>双引号</td></tr>
<tr><td>\&</td><td>和号</td><td>\\</td><td>反斜杠</td></tr>
<tr><td>\r</td><td>回车符</td><td>\t</td><td>制表符</td></tr>
<tr><td>\b</td><td>退格符</td><td>\f</td><td>换页符</td></tr>
<tr><td>\n</td><td>换行符</td><td></td><td></td></tr>
</table>

###JavaScript 变量
#####JavaScript 变量声明
JavaScript 变量用于存储字符、数字、数组甚至对象资源等，以便在我们需要的地方使用。
通过 var 关键字来声明（创建）一个变量：

    var 变量名

声明变量的例子：

    var x;
    var number;

#####JavaScript 变量命名规则
变量名以字母（a-z、A-Z）或者下划线 _ 开始，后面可以跟任意字母或数字以及下划线，但不能是空格。另外，变量名是区分大小写的。     
如下这些变量名是有效的：        

    str_str
    str
    _str
    str5

提示        
关于变量命名，我们建议变量名以标明其实际语意的组合为佳，如 my_name 或 myName 格式。          


#####JavaScript 变量赋值 
可以在声明变量的同时给变量赋值：         

    var my_name = "allen.w";
    var number = 2;

实际上，JavaScript 还支持直接给变量赋值而不用事先声明变量：    

    my_name = "allen.w";
    number = 2;

被赋值的变量会被自动声明，但预先声明一个变量，是一个良好的编程习惯。
         
实例：       

    <script type="text/javascript">
    var my_name = "allen.w";
    var age = "27";
    alert("我的名字："+my_name_"   年龄："+age);
    </script>

###JavaScript 流程控制主要是 if 和 switch 流程控制。
if 语句      
语法：     

    if(expr){
        statement
    }

该语法表示，如果 expr 表达式成立，则执行 {statement} 内的代码。      
例子：         

    <script type="text/javascript">
    var x = 3;
    var y = 1;
    if (x>y)
        alert("x大于y");
    </script>

if…else       
语法：       
运行          

    if (expr){
        statement1
    } else {
        statement2
    }

该语法表示只要 expr 成立，则执行 statement1 ，否则执行 statement2 。     
例子：      
运行       

    <script type="text/javascript">
    var x = 1;
    var y = 3;
    if (x>y)
    {
        alert("x大于y");
    } else {
        alert("x小于等于y");
    }
    </script>

运行该例子，会弹出提示框并提示文字：x小于等于y。        
if...else if...else         
语法：         
运行        

    if (expr1){
        statement1
    } else if (expr2) {
        statement2
    } else {
        statement3
    }

该语法表示只要 expr1 成立，则执行 statement1 ，否则检测 expr2 ；如果 expr2 成立则执行 statement2 ；如果 expr2 也不成立，则执行 statement3 。       
例子：       
运行       

    <script type="text/javascript">
    var x = 3;
    var y = 3;
    if (x>y) {
        alert("x大于y");
    } else if (x<y) {
        alert("x小于y");
    } else {
        alert("x等于y");
    }
    </script>

运行该例子，会弹出提示框并提示文字：x等于y。        
提示         
else if 可以有多个，以实现更多条件的选择，但多数情况下，条件更多时，我们可以选择 JavaScript switch 来实现。       
       
       
JavaScript switch        
JavaScript switch 允许对一个标量（表达式）的多个可能结果做选择。       
语法：          
运行     

    switch (expr) {
        case result1:
        statement1
        break;
        case result2:
        statement2
        break;
        ……
        default:
        statement
    }

语法解释    
系统计算 expr 的值，根据计算结果（result1、result2等）来选择执行下面对应的语句，如果所有的 case 结果都不符合，则会执行 default 里的语句。        
break 用于执行完代码后跳出流程，虽然语法上可以省略，但非特殊情况不要省略，否则会继续执行下面的代码，哪怕计算 expr 结果与 case 不符（这是与 if else 的区别）。        
例子：     
运行    

    <script type="text/javascript">
    var x = 2;
    switch (x) {
        case 0:
        alert("x等于0");
        break;
        case 1:
        alert("x等于1");
        break;
        case 2:
        alert("x等于2");
        break;
        default:
        alert("x既不等于1和2，也不等于0");
    }
    </script>
    <p>
    运行该例子，会弹出提示框并提示文字：x等于2。
    </p>

提示       
      
可以有多个 case 条件判断        
case 后面结果也不是仅限于数字，也可以是字符或其他 JavaScript 支持的类型          
default 不是必须的，如果所有的 case 结果都不符，且没有设定 default 时，则不执行任何代码          
