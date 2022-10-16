/**
 * Programa en Java que pide al usuario el radio y la altura
 * de un cilindro y calcula su volumen.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.Scanner;

public class VolumenCilindro
{
  public static void main (String[] args)
  {
    //Definimos el valor del número PI como una constante
    final double PI = 3.1415926536;
    double radio;
    double altura;

    Scanner teclado = new Scanner(System.in);

    System.out.println("Introduzca los datos del cilindro: ");
    System.out.println("Radio: ");
    radio = teclado.nextDouble();
    System.out.println("Altura: ");
    altura = teclado.nextDouble();
    System.out.println("El área del cilindro es: ");
    System.out.println(PI * radio * radio * altura);
  }
}
