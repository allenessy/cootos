<?php
header("Content-Type: text/html; charset=utf-8");
//初始化数组，但不是必须的，但可以避免错误
$arr=array();
//数组array
$arr[]='数组[0]allen';
$arr[]='数组[1]dxp';
$arr[]='数组[2]cis';
$arr['a']='数组[\'a\']';
$arr[5]='数组[5]';
echo $arr[5];
echo "<br>";
$arr = array('name'=>'数组name','password'=>'数组password');
echo $arr['name'];
echo "<br>";
$arr = array(10=>'sun','Mon','Tue');
echo $arr[12];
$name="allen";
$arr=array('xingm'=>$name);
echo "<br>";
echo "姓名：".$arr['xingm'];
echo "<br>";

$months=array(1=>'January','February','March','Aprill','May','June','July','August','September','October','November','December');
$days=range(1,31);
$years=range(1950,2013);
//foreach生成月下拉框
echo '<select name="month">';
foreach($months as $key=>$value){
  echo "<option value=\"$key\">$value</option>\n";
}
echo '</select>';
//foreach生成日期下拉框
echo '<select name="day">';
foreach($days as $key=>$value){
	echo "<option value=\"$value\">$value</option>\n";
}
echo '</select>';
//foreach生成年下拉框
echo '<select name="year">';
foreach($years as $key=>$value){
	echo "<option value=\"$value\">$value</option>\n";
}
echo '</select>';
echo "<br>";
$vb=range(20,25);
foreach($vb as $key=>$value){
	echo $key.'=>'.$value;
	echo "<br>";
}

//多维数组
$primes=array(2,3,5,7);
$sphenic=array(30,42,66,70);
$numbers=array('Primes'=>$primes,'Sphenic'=>$sphenic);
echo "The first sphenic number is {$numbers['Sphenic'][0]}";

$mexico=array(
		'YU'=>'Yucatan',
		'BC'=>'Baja California',
		'OA'=>'Oaxaca'
);

$us=array(
		'MD'=>'Maryland',
		'IL'=>'Illinois',
		'PA'=>'Pennsylvania',
		'IA'=>'Iowa'
);

$canada=array(
		'QC'=>'Quebec',
		'AB'=>'Alberta',
		'NT'=>'Northwest Territories',
		'YT'=>'Yukon',
		'PE'=>'Prince Edward Island'
);

$n_america=array(
		'Mexico'=>$mexico,
		'United States'=>$us,
		'Canada'=>$canada,
);

foreach ($n_america as $country=>$list){
	echo "<h2>$country</h2><ul>";
	foreach ($list as $k=>$v){
		echo "<li>$k-$v</li>\n";
	}
	echo '</ul>';
}
