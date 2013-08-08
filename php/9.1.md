###包含多个文件
PHP有4个用于外部文件的函数：`include()`、`include_once`、`require()`和`require_once()`    
`include()`和`require()`函数在正确工作时完全一样，但是在它们失败时会表现得有所不同。如果`include()`函数不工作(由于某种原因而不能包含文件)，就会向web浏览器打印一个警告，但是脚本会继续运行。如果`require()`失败，就会打印一个错误，并且脚本会终止运行。   
这两个函数还有一个`*_once()`版本，它们保证处理的文件只会被包含一次，而不管脚本可能(假定不经意地)试图包含它多次。   
实例1:    
header.php

    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" lang="zh-CN">
    <head profile="http://gmpg.org/xfn/11">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>网站标题</title>
    </head>
    <body>

footer.php

    </body>
    </html>

index.php

    <?php
    include ('./header.php');
    echo 'hello world!';
    include ('./footer.php');
    ?>

修改`header.php`,方便修改网站标题：

    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" lang="zh-CN">
    <head profile="http://gmpg.org/xfn/11">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title><?php echo $page_title; ?></title>
    </head>
    <body>

那么相应的index.php,也需要修改为以下：

    <?php
    $page_title='allen.w';
    include ('./header.php');
    echo 'hello world!';
    include ('./footer.php');
    ?>

###链接MySQL数据库

    <?php
    //设定编码格式
    header("Content-Type: text/html; charset=utf-8");
    // ** MySQL 设置 - 具体信息来自您正在使用的主机 ** //
    /** cis 数据库的名称 */
    define('DB_NAME','cis');
    
    /** MySQL 数据库用户名 */
    define('DB_USER', '用户名');
    
    /** MySQL 数据库密码 */
    define('DB_PASSWORD', '密码');
    
    /** MySQL 主机 */
    define('DB_HOST', 'localhost');
    
    /** 创建数据表时默认的文字编码 */
    define('DB_CHARSET', 'utf8');
    
    /** 数据库整理类型。如不确定请勿更改 */
    define('DB_COLLATE', '');

