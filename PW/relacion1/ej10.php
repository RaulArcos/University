<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Ejercicios</title>
</head>

<body>
<?php
echo "<h1>Galeria de imagenes</h1>";
function valida_foto($fotos)
{
$rdo=0;
if (preg_match("/jpg/i", $fotos)) $rdo=1;
if (preg_match("/gif/i", $fotos)) $rdo=1;
if (preg_match("/png/i", $fotos)) $rdo=1;
if (preg_match("/bmp/i", $fotos)) $rdo=1;
return $rdo;
}

echo "<table border=1>";
$puntero = opendir('fotos');
$i=1;
while (false !== ($foto = readdir($puntero)))
{
	if ($foto!="." && $foto!=".." && valida_foto($foto))
	{
	if ($i==1)
		echo "<tr>";
	echo "<td><a href='fotos/$foto'>";
	echo "<img src='fotos/$foto' width=100 height=100></img>";
	echo "</a></td>";
	if ($i==4)
		{echo "</tr>"; $i=0;}
	$i++;
	}
}
closedir($puntero);
echo "</table>";
?>
</body>
</html>
