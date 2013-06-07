<?php
header("Content-Type: text/html; charset=utf-8");

echo '<select name="year">';
for($year=1965;$year<=2013;$year++){
  $years="年";
	echo "<option value=\"$year\">$year$years\n</option>";
}
echo '</select>';

$months=array(1=>'一','二','三','四','五','六','七','八','九','十','十一','十二');
echo '<select name="month">';
foreach($months as $key=>$value){
	$month="月";
	echo "<option value=\"$key\">$value$month\n</option>";
}
echo '</select>';

echo '<select name="day">';
for ($day=1;$day<=31;$day++){
	$days="日";
	echo "<option value=\"$day\">$day$days\n</option>";
}
echo '</select>';
