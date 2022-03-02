<HTML LANG="es">

<head> <title>Práctica 1</title>
<LINK REL="stylesheet" TYPE="text/css" HREF="estilo.css">
</head>
    <h2>Ejercicio 2: Encuesta</h2>
    <?PHP
    
    ?>

    <H1>Encuesta</H1>

    <P>Cree ud. que el precio de la vivienda seguira subiendo al ritmo actual?</P>
    <form action="/action_page.php">
  <label for="fname">Título: *</label><br>
  <input type="text" id="fname" name="fname" value=""><br>
  <label for="lname">Texto: *</label><br>
  <input type="text" id="lname" name="lname" value=""><br><br>
  <p>
                              <label for="animalGroup">Type</label>
                              <select name="Group" id="Group">
                                <option>Select a type:</option>
    <?php
    foreach($Group as $m)
    {
    ?>
        <option value="<?php echo $m['Group'];?>"><?php echo $m['animalGroup'];?></option>
    <?php
    }
?>
</select></p>}
?>
  <input type="submit" value="Enviar">
</form> 

</FORM>