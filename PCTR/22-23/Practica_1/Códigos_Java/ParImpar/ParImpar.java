/**
 * Programa en Java que pide al usuario tres números enteros
 * e imprime si son pares o impares.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.Scanner;

public class ParImpar
{
  void calculaPar (int a) {
    if (a % 2 == 0)
      System.out.println("El número " + a + " es par.");
    else
      System.out.println("El número " + a + " es impar.");
  }

  public static void main (String[] args)
  {
    int num1, num2, num3;
    ParImpar obj = new ParImpar();

    Scanner teclado = new Scanner(System.in);

    System.out.print("Introduzca un número entero: ");
    num1 = teclado.nextInt();
    obj.calculaPar(num1);
    System.out.print("Introduzca otro número entero:");
    num2 = teclado.nextInt();
    obj.calculaPar(num2);
    System.out.print("Introduzca un último número entero: ");
    num3 = teclado.nextInt();
    obj.calculaPar(num3);
  }
}
