  /**
   * Programa en Java que trabaja con cadenas
   * de la clase String.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  public class Cadenas {
    public static void main(String[] args) {
      String nombre = "Juan";
      String primerApellido = "Pérez";
      String segundoApellido = "López";

      nombre += primerApellido;
      nombre += segundoApellido;

      System.out.println(nombre + " tiene " + nombre.length() + " letras");
    }
  }
