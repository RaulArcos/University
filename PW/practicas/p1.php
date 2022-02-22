<HTML LANG="es">

<head> <title>Práctica 1</title>
<LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>

<body>
    <h1>Práctica 1 PW</h1>
<div class="container-fluid">
    <h2>Ejercicio 1: consult de Noticias</h2>
    
    <?php
    $con = mysqli_connect ("localhost", "cursophp", "","lindavista")
        or die ("No se puede conectar con el servidor");

    $consult = mysqli_query ($con,"select * from noticias order by fecha desc")
        or die ("Fallo en la consult");

    $nfilas = mysqli_num_rows ($consult);

    if ($nfilas > 0){

            print ("<TABLE>\n");
            print ("<TR>\n");
            print ("<TH>Titulo</TH>\n");
            print ("<TH>Texto</TH>\n");
            print ("<TH>Categoria</TH>\n");
            print ("<TH>Fecha</TH>\n");
            print ("<TH>Imagen</TH>\n");
            print ("</TR>\n");

            for ($i=0; $i<$nfilas; $i++){
            $resultado = mysqli_fetch_array ($consult);
            print ("<TR>\n");
            print ("<TD>" . $resultado['titulo'] . "</TD>\n");
            print ("<TD>" . $resultado['texto'] . "</TD>\n");
            print ("<TD>" . $resultado['categoria'] . "</TD>\n");
            print ("<TD>" . $resultado['fecha'] . "</TD>\n");
            print ("</TR>\n");
            }
    }else
        print ("No hay noticias disponibles");

    mysqli_close ($con);
    ?>
</div>
<div class="container-fluid">
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
</BODY>
</HTML>