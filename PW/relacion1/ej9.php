<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Ejercicios</title>
</head>

<body>
<?php
if ($gestor = opendir('fotos'))
	{
	echo "<table border=1>";
	echo "<tr>";
	$i=0;
	while (false !== ($archivo = readdir($gestor)))
	{
		if ($archivo!="." && $archivo!="..")
		{
			if ($i==4)
			{
				$i=0;
				echo "</tr>";
				echo "<tr>";
			}
			$i++;
			echo "<td>";
			echo "<a href=fotos/$archivo><img src=fotos/$archivo>
			</a>";
			echo "</td>";
		}
	}
	echo "</tr>";
	echo "</table>";
	closedir($gestor);
}
?>

</body>
</html>
