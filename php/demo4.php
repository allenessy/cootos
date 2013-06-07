<?php
//数组排序
echo '<table border="0" cellspacing="3" cellpadding="3" align="center">';
echo '<tr>
<td><h2>Rating</h2></td>
<td><h2>Title</h2></td>
</tr>';
$movies=array(
	'Casablanca'=>10,
	'To kill a Mockingbird'=>10,
	'The English Patient'=>2,
	'Stranger Than Fiction'=>9,
	'Story of the Weeping Camel'=>5,
	'Donnie Darko'=>7
);

echo '<tr><td colspan="2"><b>In their original order:</b></td></tr><br>';
foreach ($movies as $title=>$rating){
	echo "<tr><td>$rating</td>
	<td>$title</td></tr>";
}

//按评级降序以数字方式对数组排序
ksort($movies);
echo '<tr><td colspan="2"><b>Sorted by title:</b></td></tr><br>';
foreach ($movies as $title=>$rating){
	echo "<tr><td>$rating</td>
	<td>$title</td></tr>";
}

//按名称以字母顺序对数组排序
arsort($movies);
echo '<tr><td colspan="2"><b>Sorted by rating:</b></td></tr><br>';
foreach ($movies as $title=>$rating){
	echo "<tr><td>$rating</td>
	<td>$title</td></tr>";
}
echo '</table>';
