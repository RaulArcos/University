<HTML LANG="es">

<head> <title>Práctica 1</title>
<LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">
</head>
    <h2>Ejercicio 2: Encuesta</h2>
    <?PHP
    if(isset($e)){
        print "Encuesta enviada correctamente";
        $con= mysqli_connect ("localhost", "cursophp", "","lindavista")
        or die ("No se puede conectar al servidor");

        $consult = mysqli_query ($con,"select v1, v2 from votos")
            or die ("Fallo en la seleccion");
        $resultado = mysqli_fetch_array ($consult);

        $v1 = $resultado["v1"];
        $v2 = $resultado["v2"];
        $voto = $_POST['voto'];
        if ($voto == "si")
        $v1 = $v1 + 1;
        else if ($voto == "no")
        $v2 = $v2 + 1;
        $instruccion = "update votos set v1=$v1, v2=$v2";
        $actualizacion = mysqli_query ($con,$instruccion)
        or die ("Fallo en la modificacion");

        mysqli_close ($con);
        header("Location: .$ej2result.php");
        die();

    }else{
    ?>

    <H1>Encuesta</H1>

    <P>Cree ud. que el precio de la vivienda seguira subiendo al ritmo actual?</P>

    <FORM ACTION="ejercicio2.php" METHOD="POST">
    <INPUT TYPE="RADIO" NAME="voto" VALUE="si" CHECKED>Si<BR>
    <INPUT TYPE="RADIO" NAME="voto" VALUE="no">No<BR><BR>
    <INPUT TYPE="SUBMIT" NAME="enviar" VALUE="votar"> 
    </FORM>

    <?PHP
    }
    ?>
</div>