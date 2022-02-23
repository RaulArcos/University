<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Ejercicios</title>
</head>

<body>
<?php



echo "Son ";
if ($_POST["conv"]==1)
{
echo $_POST["cantidad"]/166.386;
echo " euros";
}
else
{
echo $_POST["cantidad"]/180.386;
echo " dolares";
}

?>
</body>
</html>
