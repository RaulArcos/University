  /**
   * Programa en Java que pide al usuario la base y la altura
   * de un triángulo y calcula su área.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import java.util.Scanner;

  public class AreaTrian
  {
    public static void main (String[] args)
    {
      double base;
      double altura;

      Scanner teclado = new Scanner(System.in);

      System.out.println("Introduzca los datos del triángulo: ");
      System.out.print("Base: ");
      base = teclado.nextDouble();
      System.out.print("Altura: ");
      altura = teclado.nextDouble();
      System.out.print("El área del triángulo es: ");
      System.out.println((base * altura) / 2);
    }
  }
