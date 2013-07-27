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
           
JavaScript for 循环         
JavaScript for 循环用于反复执行一段代码，其语法如下：          
运行        

    for (expr1; expr2; expr3){
        statement
    }

通常在已经确定执行次数的情况下使用 for 循环，下面的例子输出1到10：        
运行        

    <script type="text/javascript">
    var i=1
    for (i = 1; i <= 10; i++) {
        document.write(i + "<br />")
    }
    </script>

运行结果：    
运行       
       
for 循环语法解读       
       
第一个表达式（expr1）在循环开始前无条件求值一次          
expr2 在每次循环开始前求值，如果值为 TRUE，则继续循环，执行嵌套的循环语句；如果值为 FALSE，则终止循环。      
expr3 在每次循环之后被求值（执行）      
每个表达式都可以为空。如果expr2 为空意则将无限循环下去，但可以通过break来结束循环，如下例子：    
运行    

    var i=1
    for (i = 1; ; i++) {
        if (i > 10) {
            break;
        }
        document.write(i + "<br />");
    }

该例子仍然输出1到10，但使用 if 条件判断，当 i>10 的时候，结束循环。      
        
提示         
在使用循环语句的时候，我们通常要注意不要无限循环而造成程序“僵死”，另外还要注意循环条件（循环判断表达式），以确保循环结果正确。      
      
JavaScript while 循环       
while 循环是 JavaScript 中最简单的循环，其语法为：          
运行   

    while (expr){
        statement
    }

该语法表示，只要 expr 表达式为 TRUE，那么就一直执行 statement 直到 expr 为 FALSE为 止，statement 表示要执行的动作或逻辑。      
下面的例子利用 while 循环输出1到10：       
运行      

    <script type="text/javascript">
    var i = 1;
    while (i <= 10) {
       document.write(i + "<br />");
       i++;
    }
    </script>

运行结果：     
运行       

    1
    2
    3
    4
    5
    6
    7
    8
    9
    10

do while循环   
do while 循环和 while 循环非常相似，其区别只是在于 do while 保证必须执行一次，而 while 在表达式不成立时则可能不做任何操作。         
do while 循环语法：      
运行    

    do {
       statement
    }while (expr)

例子：   
运行    

    var i = 1;
    do {
       document.write(i + "<br />");
       i++;
    } while (i <= 10);

该例子也是输出1到10，但与 while 循环不同的是，无论 i 的初始值是多少，都会将 i 的值至少输出1次。    
   
JavaScript for ... in    
for ... in 语句用于循环操作数组或对象属性，语法如下：   
运行     

    for (变量 in 对象)
    {
        statement
    }

for ... in 实例     
下面是一个使用 for ... in 语句遍历数组输出数组元素值的例子：         
运行       

    <script language="JavaScript">        
    var array_1 = new Array('a',10.5,true);
    var x;
    for ( x in array_1 )
    {
        document.write( array_1[x] + "<br />" );
    }      
    </script>

运行该例子，输出：       
运行    

    a
    10.5
    true

直接输出 JavaScript 数组       
当我们使用 alert() 或 document.write() 方法直接输出 JavaScript 数组时，JavaScript 会将数组元素转换成以 , 符号连接字符串输出，如下面例子所示：         
运行         

    <script language="JavaScript">   
    var array_1 = new Array('a',10.5,true);
    document.write( array_1 );
    </script>

运行该例子，输出：       
运行    

    a,10.5,true

break 和 continue 语句对循环中的代码执行提供了更严格的控制。      
break 和 continue 语句的不同之处       
break 语句可以立即退出循环，阻止再次反复执行任何代码。      
而 continue 语句只是退出当前循环，根据控制表达式还允许继续进行下一次循环。        
例如：      
运行       

    var iNum = 0;
                
    for (var i=1; i<10; i++) {
      if (i % 5 == 0) {
        break;
      }
      iNum++;
    }
    alert(iNum);

在以上代码中，for 循环从 1 到 10 迭代变量 i。在循环主体中，if 语句将（使用取模运算符）检查 i 的值是否能被 5 整除。如果能被 5 整除，将执行 break 语句。alert 显示 "4"，即退出循环前执行循环的次数。       
如果用 continue 语句代替这个例子中的 break 语句，结果将不同：      
运行     

    var iNum = 0;
               
    for (var i=1; i<10; i++) {
      if (i % 5 == 0) {
        continue;
      }
      iNum++;
    }
    alert(iNum);

这里，alert 将显示 "8"，即执行循环的次数。可能执行的循环总数为 9，不过当 i 的值为 5 时，将执行 continue 语句，会使循环跳过表达式 iNum++，返回循环开头。     
与有标签的语句一起使用        
break 语句和 continue 语句都可以与有标签的语句联合使用，返回代码中的特定位置。        
通常，当循环内部还有循环时，会这样做，例如：       
运行    

    var iNum = 0;
                
    outermost:
    for (var i=0; i<10; i++) {
      for (var j=0; j<10; j++) {
        if (i == 5 && j == 5) {
        break outermost;
      }
      iNum++;
      }
    }
                
    alert(iNum);

在上面的例子中，标签 outermost 表示的是第一个 for 语句。正常情况下，每个 for 语句执行 10 次代码块，这意味着 iNum++ 正常情况下将被执行 100 次，在执行完成时，iNum 应该等于 100。这里的 break 语句有一个参数，即停止循环后要跳转到的语句的标签。这样 break 语句不止能跳出内部 for 语句（即使用变量 j 的语句），还能跳出外部 for 语句（即使用变量 i 的语句）。因此，iNum 最后的值是 55，因为当 i 和 j 的值都等于 5 时，循环将终止。          
可以以相同的方式使用 continue 语句：   
运行    

    var iNum = 0;
                
    outermost:
    for (var i=0; i<10; i++) {
      for (var j=0; j<10; j++) {
        if (i == 5 && j == 5) {
        continue outermost;
      }
      iNum++;
      }
    }
                
    alert(iNum);

在上例中，continue 语句会迫使循环继续，不止是内部循环，外部循环也如此。当 j 等于 5 时出现这种情况，意味着内部循环将减少 5 次迭代，致使 iNum 的值为 95。        
提示：可以看出，与  break 和 continue 联合使用的有标签语句非常强大，不过过度使用它们会给调试代码带来麻烦。要确保使用的标签具有说明性，同时不要嵌套太多层循环。       

###JavaScript 函数（function）
   
什么是函数？     
函数是一组可重复使用的代码块，在 JavaScript 中，函数由事件驱动或者被其他代码调用。       
函数是 JavaScript 语言的核心之一，其基本语法如下：           
运行         

    function functionName(arg0, arg1, ...) {
        statements
    }

语法解读      
       
使用 function 关键字定义一个函数          
function 关键字空格之后紧跟函数名        
函数名字后面是一对小括弧，arg0, arg1 表示函数的参数，参数之间以 , 号分隔，参数个数可以为 0-25 个（0即表示无参数）。在没有参数时，() 括号不可省略，超过25个的参数，将被JavaScript忽略       
{} 是函数体，里面是该函数要实现的功能语句      
         
JavaScript 函数实例         
运行        

    <html>
    <head>
    <script type="text/javascript">
          
    function hello(name){
        document.write((name + "，你好！"));
    }
         
    </script>
    </head>
    <body>
    <input type="button" onclick="hello('小明')" value="确定" />
    </body>
    </html>

运行该例子，点击页面上的 确定 按钮，输出：        
运行       

    小明，你好！

事件驱动    
与前面学习的弹出《JavaScript alert 消息警告框》实例不同，该例子要弹出信息提示框，需要我们点击 确定 按钮才能实现。    
实际上这个例子就是典型的事件驱动 ，即由用户的鼠标点击事件（以及其他更多事件），来调用 hello() 函数，以执行函数内的代码。实际上大部分情况下，我们的 JavaScript 代码都是由用户事件来驱动的。    
关于事件驱动更多信息及细节，请参看《JavaScript 事件》章节。
JavaScript 函数命名    
通常，我们推荐函数的名字使用小驼峰命名法，并以函数名能大致描述该函数功能或特性为宜。小驼峰法是指，首字符小写，后面其他单词的首字母大写，下面是一些函数命名例子：    
运行    

    function changeName(){
        ...
    }
    function getAgeByInput(){
        ...
    }

也有不少人使用下划线来分割函数名中的单词，如 change_name，这也是可以的，实际执行可依照具体项目规范。    
特别地，函数前加 _ 符号（如 _getName），一般约定俗成表示类（对象）的私有方法。    
JavaScript 函数内的变量    
如果一个变量在函数体内被声明，则只能在该函数中访问该变量。这样，您可以在不同的函数内使用名称相同的变量。    
如果在函数之外声明了一个变量，则 Web 页面上的所有函数都可以访问该变量。    
    
###JavaScript 函数参数与 arguments 对象

JavaScript 函数参数     
JavaScript 函数允许没有参数（但包含参数的小括号不能省略），也可以向函数传递参数供函数使用。    
下面的例子中，就向 hello() 函数传递了 name 和 age 参数，参数值分别是 小明 和 18。    
运行   

    <html>
    <head>
    <script type="text/javascript">
        
    function hello(name,age){
        document.write("我叫" + name + "，今年" + age + "岁！");
    }
        
    </script>
    </head>
    <body>
    <input type="button" onclick="hello('小明',18)" value="确定" />
    </body>
    </html>

运行该例子，点击 确定 按钮，输出：    
运行   

    我叫小明，今年18岁！

如上例所示，传入的值是字符串时，需要加上引号；传入的值是数字，不需要加引号。    
JavaScript 函数参数错误     
JavaScript 函数参数并没有严格要求哪些参数是必选参数，哪些参数是可选参数，因此传入的参数个数是允许不等于定义函数时参数的个数的。    
如果在函数中使用了未定义的参数，则会提示语法错误（参数未定义），JavaScript 代码不会正常运行。    
如果参数已经定义，但未正确的传入参数时，相关参数值会以 undefined 替换，JavaScript 代码仍正常运行，如下例所示：    
运行   

    <html>
    <head>
    <script type="text/javascript">
        
    function hello(name,age){
        document.write("我叫" + name + "，今年" + age + "岁！");
    }
        
    </script>
    </head>
    <body>
    <input type="button" onclick="hello('小明')" value="确定" />
    </body>
    </html>

运行该例子，点击 确定 按钮，输出：    
运行   

我叫小明，今年undefined岁！   
   
JavaScript arguments 对象    
在 JavaScript 函数中，有个特殊的 arguments 对象，它以类似数组的形式保存了当前函数调用的参数。因此，开发者无需定义具体的参数名，就可以方便的访问函数参数：    
运行   

    <html>
    <head>
    <script type="text/javascript">
        
    function hello(){
        document.write("我叫" + arguments[0] + "，今年" + arguments[1] + "岁！");
    }
        
    </script>
    </head>
    <body>
    <input type="button" onclick="hello('小明',18)" value="确定" />
    </body>
    </html>

运行该例子，点击 确定 按钮，输出：    
运行   

    我叫小明，今年18岁！

在 arguments 对象中，arguments[0] 表示第1个参数，arguments[1] 表示第2个参数，依次类推。    
提示    
通常在函数定义中，为便于代码的可读性，一般不会使用 arguments 对象。在处理不定数目的参数，或者模拟函数重载时，可方便的使用 arguments 对象来处理。    
检测参数个数    
使用 arguments 对象，可以很方便的检测函数的参数个数。arguments 的 length 属性，即 arguments.length 就是参数的个数：    
运行   

    <html>
    <head>
    <script type="text/javascript">
       
    function hello(){
        document.write(arguments.length);
    }
        
    </script>
    </head>
    <body>
    <input type="button" onclick="hello('小明',18)" value="确定" />
    </body>
    </html>

运行该例子，点击 确定 按钮，输出：    
运行    

    2

JavaScript 函数的 return 语句    
      
JavaScript 函数 return   
JavaScript 函数的 return 语句用来规定从函数返回的值。当一个函数运行后，要得到一个运行结果，就需要使用 return语句来返回该结果。    
下面的例子返回两个参数值之和：    
运行    

    <script type="text/javascript">
        
    function sum(x,y){
        return x+y;
    }
    result = sum(2,3);
    document.write( result );
        
    </script>

运行该例子输出：   
运行   

    5

与 Java，PHP 等语言类似，函数在执行过 return 语句后立即停止代码，return 后面的语句都将被忽略，如：    
运行   

    <script type="text/javascript">
        
    function sum(x,y){
        return x+y;
        document.write("提示文字");
    }
        
    </script>

上面的例子中，document.write("提示文字"); 语句始终不会被执行。    
无返回值的 return 语句    
如果函数无返回值，那么可以调用没有参数的 return 运算符，随时退出函数：   
运行   

    <script type="text/javascript">
       
    function sum(x,y){
        if( x<y ){
            return; 
        }else{
        return x-y;
        }
    }
        
    </script>

提示    
如果函数无返回值，或调用了没有参数的 return 语句，那么它真正返回的值是 undefined。    
   
   
###JavaScript 事件
网页中能被 JavaScript 侦测到的行为称为 JavaScript 事件。以下是一些常见的 JavaScript 事件举例：     

页面内容被浏览器载入   
用户点击一个按钮   
用户按下某个按键    
   
事件通常和 JavaScript 函数一起配合使用，即以事件驱动函数，来完成我们希望的某些功能。     
常用 JavaScript 事件列表     
以下是常用的 JavaScript 事件列表，点击对应链接可查看每个事件具体的用法示例：    
一般事件   

<table>
<tr><td>事件属性</td><td>触发该事件的条件</td></tr>
<tr><td>onclick 事件</td><td>鼠标点击某个对象</td></tr>
<tr><td>ondblclick 事件</td><td>鼠标双击某个对象</td></tr>
<tr><td>onmousedown 事件</td><td>按下鼠标键</td></tr>
<tr><td>onmouseup 事件</td><td>鼠标键按下后松开</td></tr>
<tr><td>onmouseover 事件</td><td>鼠标移动到某对象范围的上方</td></tr>
<tr><td>onmouseout 事件</td><td>鼠标离开某对象范围</td></tr>
<tr><td>onkeydown 事件</td><td>键盘上某个按键被按下</td></tr>
<tr><td>onkeypress 事件</td><td>键盘上某个键被按下或按住</td></tr>
<tr><td>onkeyup 事件</td><td>键盘上某个键（按下后）被松开</td></tr>
</table>
表单相关事件
<table>
<tr><td>事件属性</td><td>触发该事件的条件</td></tr>
<tr><td>onblur 事件</td><td>元素失去焦点</td></tr>
<tr><td>onfocus 事件</td><td>元素获得焦点</td></tr>
<tr><td>onchange 事件</td><td>用户改变表单域的内容</td></tr>
<tr><td>onsubmit 事件</td><td>表单提交按钮被点击</td></tr>
<tr><td>onreset 事件</td><td>表单重置按钮被点击</td></tr>
</table>

页面相关事件

<table>
<tr><td>事件属性</td><td>触发该事件的条件</td></tr>
<tr><td>onload 事件</td><td>页面或图像（被浏览器）加载完成</td></tr>
<tr><td>onunload 事件</td><td>用户退出页面（或页面改变为其他页面）</td></tr>
<tr><td>onerror 事件</td><td>当加载文档或图像时发生某个错误</td></tr>
<tr><td>onresize 事件</td><td>窗口或框架被调整尺寸</td></tr>
<tr><td>onmove 事件</td><td>窗口或框架被移动</td></tr>
<tr><td>onscroll 事件</td><td>浏览器的滚动条位置发生变化</td></tr>
<tr><td>onstop 事件</td><td>浏览器的停止按钮被按下或者正在下载的文件被中断</td></tr>
</table>
编辑事件
<table>
<tr><td>事件属性</td><td>触发该事件的条件</td></tr>
<tr><td>onselect 事件</td><td>当文本内容被选择</td></tr>
<tr><td>onbeforecopy 事件</td><td>当页面被选择内容将要复制到系统剪贴板前</td></tr>
<tr><td>oncopy 事件</td><td>当前被选择的内容被复制后</td></tr>
<tr><td>oncut 事件</td><td>当前被选择的内容被剪切</td></tr>
<tr><td>onpaste 事件</td><td>当内容被粘贴时</td></tr>
</table>
