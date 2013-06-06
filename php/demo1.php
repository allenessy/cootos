<?php

//声明变量，并打印变量值
$var="Hello,world!";  
echo "$var";
echo "<br>";

//声明常量，并打印常量值
define ('ABSPATH', dirname(__FILE__));
echo ABSPATH;
echo "<br>";

//单引号照字面意义进行处理
echo '$var';
echo "<br>";
//双引号内的值将被打印
echo "$var";
echo "<br>";
