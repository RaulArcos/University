<HTML LANG="es">

<HEAD>
   <TITLE>Consulta de noticias</TITLE>
   <LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">

<?PHP
// Incluir bibliotecas de funciones
   //include ("lib/fecha.php");
?>

</HEAD>

<BODY>

<H1>Consulta de noticias</H1>

<?PHP

   // Conectar con el servidor de base de datos seleccionando lindavista
      $conexion = mysqli_connect ("localhost", "cursophp", "","lindavista")
         or die ("No se puede conectar con el servidor");



   // Enviar consulta
      $instruccion = "select * from noticias order by fecha desc";
      $consulta = mysqli_query ($conexion,$instruccion)
         or die ("Fallo en la consulta");

   // Mostrar resultados de la consulta
      $nfilas = mysqli_num_rows ($consulta);
      if ($nfilas > 0)
      {
         print ("<TABLE>\n");
         print ("<TR>\n");
         print ("<TH>Titulo</TH>\n");
         print ("<TH>Texto</TH>\n");
         print ("<TH>Categoria</TH>\n");
         print ("<TH>Fecha</TH>\n");
         print ("<TH>Imagen</TH>\n");
         print ("</TR>\n");

         for ($i=0; $i<$nfilas; $i++)
         {
            $resultado = mysqli_fetch_array ($consulta);
            print ("<TR>\n");
            print ("<TD>" . $resultado['titulo'] . "</TD>\n");
            print ("<TD>" . $resultado['texto'] . "</TD>\n");
            print ("<TD>" . $resultado['categoria'] . "</TD>\n");
            print ("<TD>" . $resultado['fecha'] . "</TD>\n");

            if ($resultado['imagen'] != "")
               print ("<TD><A TARGET='_blank' HREF='img/" . $resultado['imagen'] .
                      "'><IMG BORDER='0' SRC='img/ico-fichero.gif' ALT='Imagen asociada'></A></TD>\n");
            else
               print ("<TD>&nbsp;</TD>\n");

            print ("</TR>\n");
         }

         print ("</TABLE>\n");
      }
      else
         print ("No hay noticias disponibles");

// Cerrar conexion
   mysql_close ($conexion);

?>

</BODY>
</HTML>
