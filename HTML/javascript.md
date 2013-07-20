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

