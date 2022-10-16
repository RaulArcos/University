/**
 * Programa en Java que pide al usuario la cantidad de dinero ingresado 
 * y el interés anual y calcula el interés obtenido a los 6 meses.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.*;

public class CalculoIntereses
{
  /**El método main recibe como argumento un array de cadenas de
   * caracteres.
   *@param args array de cadenas de caracteres
   *@exception no se generan excepciones
   */
  public static void main (String[] args)
  {
    Scanner teclado = new Scanner(System.in);

    System.out.println("Cálculo de intereses.");
    System.out.println("Dinero ingresado:");
    //Hay que separar los decimales con coma (,)
    float dinero = teclado.nextFloat();
    System.out.println("Interes anual (%): ");
    float interes = teclado.nextFloat();
    float ganancia = dinero*interes/100/2;
    System.out.println("Intereses a los seis meses: " + ganancia);
    System.out.println("Dinero disponible en total a los seis meses: " + (dinero + ganancia));
  }
}
