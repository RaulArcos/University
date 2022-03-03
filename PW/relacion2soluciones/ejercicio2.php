<HTML LANG="es">

<HEAD>
   <TITLE>Encuesta</TITLE>
   <LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">
</HEAD>

<BODY>

<?PHP
   error_reporting(E_ALL & ~E_NOTICE);
   $enviar = $_POST['enviar'];
   if (isset($enviar))
   {
      print ("<H1>Encuesta. Voto registrado</H1>\n");

   // Conectar con la base de datos
      $connection = mysqli_connect ("localhost", "cursophp-ad", "php.hph","lindavista")
         or die ("No se puede conectar al servidor");


   // Obtener votos actuales
      $instruccion = "select votos1, votos2 from votos";
      $consulta = mysqli_query ($connection,$instruccion)
         or die ("Fallo en la seleccion");
      $resultado = mysqli_fetch_array ($consulta);

  // Actualizar votos
     $votos1 = $resultado["votos1"];
     $votos2 = $resultado["votos2"];
     $voto = $_POST['voto'];
     if ($voto == "si")
        $votos1 = $votos1 + 1;
     else if ($voto == "no")
        $votos2 = $votos2 + 1;
     $instruccion = "update votos set votos1=$votos1, votos2=$votos2";
     $actualizacion = mysqli_query ($connection,$instruccion)
        or die ("Fallo en la modificacion");

   // Desconectar
      mysqli_close ($connection);

   // Mostrar mensaje de agradecimiento
      print ("<P>Su voto ha sido registrado. Gracias por participar</P>\n");
      print ("<A HREF='ejercicio2-resultados.php'>Ver resultados</A>\n");
   }
   else
   {
?>

<H1>Encuesta</H1>

<P>Cree ud. que el precio de la vivienda seguira subiendo al ritmo actual?</P>

<FORM ACTION="ejercicio2.php" METHOD="POST">
   <INPUT TYPE="RADIO" NAME="voto" VALUE="si" CHECKED>Si<BR>
   <INPUT TYPE="RADIO" NAME="voto" VALUE="no">No<BR><BR>
   <INPUT TYPE="SUBMIT" NAME="enviar" VALUE="votar"> 
</FORM>

<A HREF="ejercicio2-resultados.php">Ver resultados</A>

<?PHP
   }
?>

</BODY>
</HTML>
