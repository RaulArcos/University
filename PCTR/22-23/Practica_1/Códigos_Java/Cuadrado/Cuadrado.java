/**
 * Programa en Java que pide al usuario el lado de 
 * un cuadrado, y muestra su área y su perímetro.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.*;

public class Cuadrado
{
  /**El método main recibe como argumento
   * un array de cadenas de caracteres.
   *@param args array de cadenas de caracteres
   *@exception no se generan excepciones
   */
  public static void main (String[] args)
  {
    System.out.println("El lado del cuadrado mide: ");
    Scanner teclado = new Scanner(System.in);
    double lado = teclado.nextDouble();
    System.out.println("El perímetro del cuadrado es " + lado * 4);
    System.out.println("El área del cuadrado es " + lado * lado);
  }
}
