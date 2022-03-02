<HTML LANG="es">

<HEAD>
   <TITLE>Encuesta. Resultados de la votacion</TITLE>
   <LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">
</HEAD>

<BODY>

<H1>Encuesta. Resultados de la votacion</H1>

<?PHP

   // Conectar con la base de datos
      $connection = mysqli_connect ("localhost", "cursophp-ad", "php.hph", "lindavista")
         or die ("No se puede conectar al servidor");


   // Obtener datos actuales de la votacion
      $instruccion = "select * from votos";
      $consulta = mysqli_query ($connection,$instruccion)
         or die ("Fallo en la seleccion");
      $resultado = mysqli_fetch_array ($consulta);

      $votos1 = $resultado["votos1"];
      $votos2 = $resultado["votos2"];
      $totalVotos = $votos1 + $votos2;

   // Mostrar resultados
      print ("<TABLE>\n"); 

      print ("<TR>\n");
      print ("<TH>Respuesta</TH>\n");
      print ("<TH>Votos</TH>\n");
      print ("<TH>Porcentaje</TH>\n");
      print ("<TH>Representacion grafica</TH>\n");
      print ("</TR>\n");

      $porcentaje = round (($votos1/$totalVotos)*100,2);
      print ("<TR>\n");
      print ("<TD CLASS='izquierda'>Si</TD>\n");
      print ("<TD CLASS='derecha'>$votos1</TD>\n");
      print ("<TD CLASS='derecha'>$porcentaje%</TD>\n");
      print ("<TD CLASS='izquierda'><IMG SRC='img/puntoamarillo.gif' HEIGHT='10' WIDTH='" .
         $porcentaje*4 . "'></TD>\n");
      print ("</TR>\n");

      $porcentaje = round (($votos2/$totalVotos)*100,2);
      print ("<TR>\n");
      print ("<TD CLASS='izquierda'>No</TD>\n");
      print ("<TD CLASS='derecha'>$votos2</TD>\n");
      print ("<TD CLASS='derecha'>$porcentaje%</TD>\n");
      print ("<TD CLASS='izquierda'><IMG SRC='img/puntoamarillo.gif' HEIGHT='10' WIDTH='" .
         $porcentaje*4 . "'></TD>\n");
      print ("</TR>\n");

      print ("</TABLE>\n");

      print ("<P>Numero total de votos emitidos: $totalVotos </P>\n");

      print ("<P><A HREF='ejercicio2.php'>Pagina de votacion</A></P>\n");

   // Desconectar
      mysqli_close ($connection);

?>

</BODY>
</HTML>
