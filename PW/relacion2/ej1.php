<HTML LANG="es">

<head> <title>Práctica 1</title>
<LINK REL="stylesheet" TYPE="text/css" HREF="/estilo.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>

<body>
    <h1>Práctica 1 PW</h1>
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
</BODY>
</HTML>