在创建数据库和表时，应该提供清楚、有意义和易于输入的名名称

 - 应该只含字母、数字和下划线（不含空格）
 - 不应该与现有的关键字相同（就像SQL名词或函数名称一样）
 - 应该区分大小写
 - 不能长于64个字符（大约如此）
 - 在其域内必须是唯一的

最后一条规则意味着表不能有两个列的名称相同，数据库不能有两个表的名称相同。不过，可以在同一个数据库的两个不同的表中使用相同的列名（事实上你通常会这么做）。   
查看当前存在的所有数据库：

    SHOW DATABASES;

创建test数据库：

    CREATE DATABASE test;

查看创建好的test数据库定义：

    SHOW CREATE DATABASE test\G;

删除数据库：

    DROP DATABASE test;

查看系统支持的存储引擎类型：

    SHOW ENGINES\G;

查看系统默认存储引擎：

    SHOW VARIABLES LIKE 'storage_engine';

查看MySQL所支持的编码(字符集)：

    SHOW CHARACTER SET;

MySQL中的每种编码都有一种或多种校对规则（collation）。校对规则是在字符集内用于比较字符的一套规则。

    SHOW COLLATION LIKE 'utf8%';

选择当前数据库为test:

    USE test;


在创建数据库表时，MySQL要求明确指出每个列将包含哪一类信息。主要有3类信息，几乎所有的数据库应用程序都是如此：

 - 文本（即字符串）
 - 数字
 - 日期和时间

MySQL数据类型
<table>
<tr>
<td>类型</td><td>大小</td><td>描述</td>
</tr>
<tr>
<td>CHAR[Length]</td><td>Length字节</td><td>定长字段，长度为0~255个字符</td>
</tr>
<tr>
<td>VARCHAR[Length]</td><td>String长度+1字节或String长度+2字节</td><td>变长字段，长度为0~65535个字符</td>
</tr>
<tr>
<td>TINYTEXT</td><td>String长度+1字节</td><td>字符串，最大长度为255个字符</td>
</tr>
<tr>
<td>TEXT</td><td>String长度+2字节</td><td>字符串，最大长度为65535个字符</td>
</tr>
<tr>
<td>MEDIUMTEXT</td><td>String长度+3字节</td><td>字符串，最大长度为16777215个字符</td>
</tr>
<tr>
<td>LONGTEXT</td><td>String长度+4字节</td><td>字符串，最大长度为4294967295个字符</td>
</tr>
<tr>
<td>TINYINT[Length]</td><td>1字节</td><td>范围：-128~127，或者0~255（无符号）</td>
</tr>
<tr>
<td>SMALLINT[Length]</td><td>2字节</td><td>范围：-32768~32767，或者0~65535（无符号）</td>
</tr>
<tr>
<td>MEDIUMINT[Length]</td><td>3字节</td><td>范围：-8388608~8388607，或者0~16777215（无符号）</td>
</tr>
<tr>
<td>INT[Length]</td><td>4字节</td><td>范围：-2147483648~2147483647，或者0~4294967295</td>
</tr>
<tr>
<td>BIGINT[Length]</td><td>8字节</td><td>范围：-9223372036854775808~9223372036854775807，或者0~18446744073709551615（无符号）</td>
</tr>
<tr>
<td>FLOAT[Length,Decimals]</td><td>4字节</td><td>具有浮动小数点的较小的数</td>
</tr>
<tr>
<td>DOUBLE[Length,Decimals]</td><td>8字节</td><td>具有浮动小数点的较大的数</td>
</tr>
<tr>
<td>DECIMAL[Length,Decimals]</td><td>Length+1字节或Length+2字节</td><td>存储为字符串的DOUBLE,允许固定的小数点</td>
</tr>
<tr>
<td>DATE</td><td>3字节</td><td>采用YY-MM-DD格式</td>
</tr>
<tr>
<td>DATETIME</td><td>8字节</td><td>采用YYYY-MM-DD HH:MM:SS格式</td>
</tr>
<tr>
<td>TIMESTAMP</td><td>4字节</td><td>采用YYYYMMDDHHMMSS格式：可接受的范围起始于1970年终止于2038年</td>
</tr>
<tr>
<td>TIME</td><td>3字节</td><td>采用HH:MM:SS格式</td>
</tr>
<tr>
<td>ENUM</td><td>1或2字节</td><td>enumeration(枚举)的简写，这意味着每一列都可以具有多个可能的值之一</td>
</tr>
<tr>
<td>SET</td><td>1、2、3、4或8字节</td><td>与ENUM一样，只不过每一列都可以具有多个可能的值</td>
</tr>
</table>

实例：

<table>
<tr><td>备注</td><td>字段名称</td><td>数据类型</td><td>主键约束</td><td>非空约束</td><td>唯一性约束</td><td>默认约束</td><td>自动增加</td></tr>
<tr><td>自增ID</td><td>id</td><td>INT</td><td>PRIMARY KEY</td><td>NOT NULL</td><td></td><td></td><td>AUTO_INCREMENT</td></tr>
<tr><td>用户名</td><td>name</td><td>VARCHAR(45)</td><td></td><td>NOT NULL</td><td>UNIQUE</td><td></td><td></td></tr>
<tr><td>密码</td><td>password</td><td>VARCHAR(45)</td><td></td><td>NOT NULL</td><td></td><td></td><td></td></tr>
<tr><td>性别</td><td>gender</td><td>VARCHAR(10)</td><td></td><td>NOT NULL</td><td></td><td>DEFAULT 'M'</td><td></td></tr>
<tr><td>生日</td><td>birthdate</td><td>VARCHAR(45)</td><td></td><td></td><td></td><td></td><td></td></tr>
<tr><td>密码提示问题</td><td>question</td><td>VARCHAR(45)</td><td></td><td></td><td></td><td></td><td></td></tr>
<tr><td>密码提示答案</td><td>answer</td><td>VARCHAR(45)</td><td></td><td></td><td></td><td></td><td></td></tr>
<tr><td>地址</td><td>address</td><td>VARCHAR(45)</td><td></td><td></td><td></td><td></td><td></td></tr>
<tr><td>电话</td><td>phone</td><td>INT(11)</td><td></td><td></td><td></td><td></td><td></td></tr>
<tr><td>E-mail</td><td>email</td><td>VARCHAR(45)</td><td></td><td></td><td>UNIQUE</td><td></td><td></td></tr>
<tr><td>注册时间</td><td>registerdatetime</td><td>TIMESTAMP</td><td></td><td></td><td></td><td></td><td></td></tr>
</table>
