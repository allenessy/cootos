###格式化日期和时间
在DATE_FORMAT()和TIME_FORMAT()函数中使用的参数
<table>
<tr><td>名词</td><td>用法</td><td>示例</td></tr>
<tr><td>%e</td><td>一月中的某一天</td><td>1~31</td></tr>
<tr><td>%d</td><td>一月中的某一天,用两位数表示</td><td>01~31</td></tr>
<tr><td>%D</td><td>带后缀的天</td><td>1st~31st</td></tr>
<tr><td>%W</td><td>每周中的日名称</td><td>Sunday~Saturday</td></tr>
<tr><td>%a</td><td>简写的每周中的日名称</td><td>Sun~Sat</td></tr>
<tr><td>%c</td><td>月份编号</td><td>1~12</td></tr>
<tr><td>%m</td><td>月份编号，用两位数字表示</td><td>01~12</td></tr>
<tr><td>%M</td><td>月份名称</td><td>January~December</td></tr>
<tr><td>%b</td><td>简写的月份名称</td><td>Jan~Dec</td></tr>
<tr><td>%Y</td><td>年份</td><td>2002</td></tr>
<tr><td>%y</td><td>年份</td><td>02</td></tr>
<tr><td>%l</td><td>小时(小写L)</td><td>1~12</td></tr>
<tr><td>%h</td><td>小时，用两位数字表示</td><td>01~12</td></tr>
<tr><td>%k</td><td>小时，24小时制</td><td>0~23</td></tr>
<tr><td>%H</td><td>小时，24小时制，用两位数字表示</td><td>00~23</td></tr>
<tr><td>%i</td><td>分钟</td><td>00~59</td></tr>
<tr><td>%S</td><td>秒</td><td>00~59</td></tr>
<tr><td>%r</td><td>时间</td><td>8:17:02 PM</td></tr>
<tr><td>%T</td><td>时间，24小时制</td><td>20:17:02</td></tr>
<tr><td>%p</td><td>上午或下午</td><td>AM或PM</td></tr>
</table>
实例：

	select date_format(now(),'%d %b %Y %T');

