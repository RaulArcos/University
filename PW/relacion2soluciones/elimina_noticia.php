<HTML LANG="es">

<HEAD>
   <TITLE>Eliminacion de noticias</TITLE>
   <LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">

<?PHP
// Incluir bibliotecas de funciones
   //include ("lib/fecha.php");
?>

</HEAD>

<BODY>

<H1>Eliminacion de noticias</H1>

<?PHP
error_reporting(E_ALL & ~E_NOTICE);

   $eliminar = $_REQUEST['eliminar'];
   if (isset($eliminar))
   {

   // Conectar con el servidor de base de datos
      $conexion = mysqli_connect ("localhost", "cursophp-ad", "php.hph", "lindavista")
         or die ("No se puede conectar con el servidor");



   // Obtener numero de noticias a borrar
      $borrar = $_REQUEST['borrar'];
      $nfilas = count ($borrar);

   // Mostrar noticias a borrar
      for ($i=0; $i<$nfilas; $i++)
      {

      // Obtener datos de la noticia i-�sima
         $instruccion = "select * from noticias where id = $borrar[$i]";
         $consulta = mysqli_query ($conexion, $instruccion)
            or die ("Fallo en la consulta");
         $resultado = mysqli_fetch_array ($consulta);

      // Mostrar datos de la noticia i-esima
         print ("Noticia eliminada:\n");
         print ("<UL>\n");
         print ("   <LI>Titulo: " . $resultado['titulo']);
         print ("   <LI>Texto: " . $resultado['texto']);
         print ("   <LI>Categoria: " . $resultado['categoria']);
         print ("   <LI>Fecha: " . $resultado['fecha']);
         if ($resultado['imagen'] != "")
            print ("   <LI>Imagen: " . $resultado['imagen']);
         else
            print ("   <LI>Imagen: (no hay)");
         print ("</UL>\n");

      // Eliminar noticia
         $instruccion = "delete from noticias where id = $borrar[$i]";
         $consulta = mysqli_query ($conexion,$instruccion)
            or die ("Fallo en la eliminacion");

      // Borrar imagen asociada si existe
         if ($resultado['imagen'] != "")
         {
            $nombreFichero = "img/" . $resultado['imagen'];
            unlink ($nombreFichero);
         }

      }
      print ("<P>Numero total de noticias eliminadas: " . $nfilas . "</P>\n");

   // Cerrar conexi�n
      mysqli_close ($conexion);

      print ("<P>[ <A HREF='elimina_noticia.php'>Eliminar mas noticias</A> ]</P>\n");

   }
   else
   {

   // Conectar con el servidor de base de datos
      $conexion = mysqli_connect ("localhost", "cursophp-ad", "php.hph", "lindavista")
         or die ("No se puede conectar con el servidor");


   // Enviar consulta
      $instruccion = "select * from noticias order by fecha desc";
      $consulta = mysqli_query ($conexion,$instruccion)
         or die ("Fallo en la consulta");

   // Mostrar resultados de la consulta
      $nfilas = mysqli_num_rows ($consulta);
      if ($nfilas > 0)
      {
         print ("<FORM ACTION='elimina_noticia.php' METHOD='post'>\n");

         print ("<TABLE>\n");
         print ("<TR>\n");
         print ("<TH>Titulo</TH>\n");
         print ("<TH>Texto</TH>\n");
         print ("<TH>Categoria</TH>\n");
         print ("<TH>Fecha</TH>\n");
         print ("<TH>Imagen</TH>\n");
         print ("<TH>Borrar</TH>\n");
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

            print ("<TD><INPUT TYPE='CHECKBOX' NAME='borrar[]' VALUE='" .
               $resultado['id'] . "'></TD>\n");

            print ("</TR>\n");
         }

         print ("</TABLE>\n");

         print ("<BR>\n");
         print ("<INPUT TYPE='SUBMIT' NAME='eliminar' VALUE='Eliminar noticias marcadas'>\n");
         print ("</FORM>\n");
      }
      else
         print ("No hay noticias disponibles");

   // Cerrar conexi�n
      mysqli_close ($conexion);

   }

?>

</BODY>
</HTML>
