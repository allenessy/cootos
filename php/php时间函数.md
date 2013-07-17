在`php.ini`中设置时区

	date.timezone = PRC

`date_default_timezone_set()` 函数设置用在脚本中所有日期/时间函数的默认时区。

设置中国时区

  	date_default_timezone_set('Asia/Shanghai');//'Asia/Shanghai' 亚洲/上海
	date_default_timezone_set('Asia/Chongqing');//其中Asia/Chongqing'为“亚洲/重庆”
	date_default_timezone_set('PRC');//其中PRC为“中华人民共和国”
	ini_set('date.timezone','Etc/GMT-8');
	ini_set('date.timezone','PRC');
	ini_set('date.timezone','Asia/Shanghai');
	ini_set('date.timezone','Asia/Chongqing');

注：以上几种方法，任意一个都可以满足我们需求。

日期时间函数`date()`
<table>
<tr><td>名词</td><td>用法</td><td>示例</td></tr>
<tr><td>Y</td><td>年份</td><td>2002</td></tr>
<tr><td>y</td><td>年份</td><td>02</td></tr>
<tr><td>F</td><td>月份名称</td><td>January~December</td></tr>
<tr><td>M</td><td>简写的月份名称</td><td>Jan~Dec</td></tr>
<tr><td>m</td><td>月份编号，用两位数字表示</td><td>01~12</td></tr>
<tr><td>n</td><td>月份编号</td><td>1~12</td></tr>
<tr><td>j</td><td>一月中的某一天</td><td>1~31</td></tr>
<tr><td>d</td><td>一月中的某一天,用两位数表示</td><td>01~31</td></tr>
<tr><td>jS</td><td>带后缀的天</td><td>1st~31st</td></tr>
<tr><td>G</td><td>小时，24小时制</td><td>0~23</td></tr>
<tr><td>H</td><td>小时，24小时制，用两位数字表示</td><td>00~23</td></tr>
<tr><td>g</td><td>小时</td><td>1~12</td></tr>
<tr><td>h</td><td>小时，用两位数字表示</td><td>01~12</td></tr>
<tr><td>i</td><td>分钟</td><td>00~59</td></tr>
<tr><td>s</td><td>秒</td><td>00~59</td></tr>
<tr><td>a</td><td>上午或下午</td><td>am或pm</td></tr>
<tr><td>A</td><td>上午或下午</td><td>AM或PM</td></tr>
<tr><td>l</td><td>星期名称</td><td>Monday~Sunday</td></tr>
<tr><td>D</td><td>简写的星期名称</td><td>Mon~Sun</td></tr>
<tr><td>w</td><td>星期名称，数字表示</td><td>1~7</td></tr>
<tr><td>W</td><td>一年中的星期数</td><td>1~52</td></tr>
<tr><td>t</td><td>本月的天数</td><td>28~31</td></tr>
<tr><td>z</td><td>今天是今年的第n天</td><td>1~365</td></tr>
<tr><td>L</td><td>今年是否是闰年</td><td>0~1</td></tr>
<tr><td>T</td><td>服务器的时间区域设置</td><td>UTC、PRC</td></tr>
</table>

实例：

	$datetime=date('d M Y H:i:s');
	echo $datetime;
