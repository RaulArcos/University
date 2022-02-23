<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Ejercicios</title>
</head>

<body>

<?php
echo "<table border=1>";
$n=1;
for ($n1=1; $n1<=10; $n1++)
{
	echo "<tr>";
	for ($n2=1; $n2<=10; $n2++)
	{
		echo "<td>", $n, "</td>";
		$n=$n+1;
	}
	echo "</tr>";
}
echo "</table>";
?>

</body>
</html>
