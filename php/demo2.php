<?php
header("Content-Type: text/html; charset=utf-8");
$x=10;
//if语句
if($x<10){
  echo "x小于10";
}elseif($x>10){
	echo "x大于10";
}else{
	echo "x等于10";
}

echo "<br>";
echo "姓名:<input type=\"text\"></input>";
echo "<br>";
$name = "allen";
$wel="欢迎您";

//switch语句
switch ($cis="M"){
	case "F":
		echo $wel.$name."女士";
		break;
	case "M":
		echo $wel.$name."先生";
		break;
	default:
		echo "欢迎来到cis";
		break;
}
