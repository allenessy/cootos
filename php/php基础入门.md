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
