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

每一个指令集以 ; 符号结束

