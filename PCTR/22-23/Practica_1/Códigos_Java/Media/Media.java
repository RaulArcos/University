/**
 * Programa en Java que pide al usuario dos números
 * y calcula su media.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.Scanner;

public class Media {
  public static void main (String[] args)
  {
    double med, x, y;

    Scanner teclado = new Scanner(System.in);

    med = 0;
    System.out.print("Introduzca un número: ");
    x = teclado.nextDouble();
    System.out.print("Introduzca el otro número: ");
    y = teclado.nextDouble();
    med = (x + y) / 2;
    System.out.println("La media de " + x + " y " + y + " es " + med);
  }
}
