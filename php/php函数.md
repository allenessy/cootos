###创建自己的函数
PHP具有许多内置函数，可以应对几乎所有的需要。      
建立自己的函数语法如下：      

function function_name(){
  //function code
}
你的函数名称可以是字母、数字和下划线的任意组合，但是它必须以字母或下划线开头。你还不能为自己的函数使用现有的函数名（print、echo、isset等）       
在PHP中，函数名称不区分大小写(与变量名称不同)      
      
函数内的代码几乎可以做任何事情，从生成HTML代码到预先格式化计算。         
创建自定义函数最常见的目的如下所述：         

 - 将重复代码关联到一个函数调用中
 - 将敏感或复杂的过程独立出来
 - 让常用代码更易于重用

#####创建自定义函数

	<?php
	function create_add(){
		echo '广告';
		echo '<br />';
	}
	create_add();
	?>
	<?php create_add(); ?>

这个函数，在脚本中被调用两次，创建两个广告。      

#####创建带参数的函数
函数可以带有任意数量的参数，但是它们的排列顺序很重要。将变量添加到函数定义中以允许使用参数：

	function print_hello($first,$last){
		//function code
	}

使用函数创建单选按钮：

	function input_add($a1,$a2){
			echo '<input name="gender" type="radio" value="' .$a1.'" />'.$a2;
	}
	input_add('M', '男');
	input_add('F', '女');

#####设置默认的参数值

定义自己的函数的另一个变体是预先设置参数的值。要这样做，可以在函数定义中给参数赋值：

	function greet($name,$msg='hello'){
		echo "$msg,$name!";
	}
	greet('sam');
	greet('zoe','Good morning');

设置默认参数值的最终结果是，当调用函数时，特定参数变为可选的。如果把一个值传递给它，就会使用传递的值；否则，就会使用默认值。         
你可以根据需要为多个参数设置默认值，只要这些参数出现在函数定义的最后面即可。换句话说，必需的参数应该总是出现在最前面。        
