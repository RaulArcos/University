/**
 * Programa en Java que pide al usuario las dimensiones de
 * un rectángulo y lo imprime por pantalla.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.Scanner;

public class Rectangulo
{
  void imprimeRectangulo (int base, int alt) {
    int a = 1, b = 1;

    do {
      b = 1;

      do {
        System.out.print("* ");
        ++b;
      } while(b <= base);
      System.out.println();
      ++a;
    } while(a <= alt);
    System.out.println();
  }

  public static void main (String[] args)
  {
    int base, altura;
    Rectangulo rect = new Rectangulo();

    Scanner teclado = new Scanner(System.in);

    System.out.print("Introduzca el valor de la base: ");
    base = teclado.nextInt();
    System.out.print("Introduzca el valor de la altura: ");
    altura = teclado.nextInt();
    rect.imprimeRectangulo(base, altura);
  }
}
