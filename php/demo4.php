<?php
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
	echo "<ul><li>$rating</li>
	<li>$title</li></ul>";
}

ksort($movies);
echo '<tr><td colspan="2"><b>Sorted by title:</b></td></tr><br>';
foreach ($movies as $title=>$rating){
	echo "<ul><li>$rating</li>
	<li>$title</li></ul>";
}

arsort($movies);
echo '<tr><td colspan="2"><b>Sorted by rating:</b></td></tr><br>';
foreach ($movies as $title=>$rating){
	echo "<ul><li>$rating</li>
	<li>$title</li></ul>";
}
