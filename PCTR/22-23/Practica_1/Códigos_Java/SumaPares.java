  /**
   * Programa en Java que calcula la suma de los n
   * primeros números pares.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import java.util.Scanner;

  public class SumaPares {
    public static void main(String[] args) {
      Scanner teclado = new Scanner(System.in);
      int numero, suma = 0;

      System.out.print("Introduzca el número n: ");
      numero = teclado.nextInt();

      for(int i = 0; i < 2 * numero ; i = i + 2) {
        suma = suma + i;
      }

      System.out.println("La suma de los primeros " + numero + " numeros pares es: " +
        suma);
    }
  }
