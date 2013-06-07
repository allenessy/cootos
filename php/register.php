<?php 
header("Content-Type: text/html; charset=utf-8");
echo '<form action="demo2.php" method="post">';
echo '<p><label>用户名:<input type="text" name="name" size="20" maxlength="40" /></label></p>';
echo '<p><label for="gender">性别:</label><input type="radio" name="gender" value="M" />男<input type="radio" name="gender" value="F" />女</p>';
echo '<p><input type="submit" name="submit" value="提交" /></p>';
echo '</form>';
