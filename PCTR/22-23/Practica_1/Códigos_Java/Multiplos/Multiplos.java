/**
 * Programa en Java que muestra los 10 primeros múltiplos de 29.
 *
 * @author Natalia Partera
 * @version 1.0
 */

public class Multiplos
{
  public static void main (String[] args)
  {
    int n = 1, x = 29;

    System.out.print("Los 10 primeros múltiplos de 29 son: ");
    for(; n <= 10; ++n) {
      System.out.print(x * n + " ");
    }
    System.out.println(" ");
  }
}
