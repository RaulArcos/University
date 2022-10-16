/**
 * Programa en Java que muestra mis datos.
 *
 * @author Natalia Partera
 * @version 1.0
 */


public class MisDatos
{
  String nombre = "Sara";
  String apellidos = "Sánchez Sánchez";
  String ciudad = "Cádiz";
  String ocupacion = "estudiante";
  int edad = 22;
  int asignaturasAprobadas = 12;
  int asignaturasCursadas = 15;

  public int asigSuspensas (int asigCursadas, int asigAprobadas)
  {
    return (asigCursadas - asigAprobadas);
  }

  public static void main (String[] args)
  {
    MisDatos yo = new MisDatos();

    System.out.println("Me llamo " + yo.nombre + " " + yo.apellidos + ".");
    System.out.println("Vivo en " + yo.ciudad + " y tengo " + yo.edad + " años.");
    System.out.println("Soy " + yo.ocupacion + ". He cursado " + yo.asignaturasCursadas + " asignaturas: he aprobado " + yo.asignaturasAprobadas + ", y he suspendido " + yo.asigSuspensas(yo.asignaturasCursadas, yo.asignaturasAprobadas) + ".");
  }
}
