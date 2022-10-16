  /**
   * Programa en Java que cuenta el número de
   * vocales de un texto dado.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import java.util.Scanner;

  public class CuentaVocales {
    public static void main(String[] args) {
      int vocalA, vocalE, vocalI, vocalO, vocalU;
      vocalA = vocalE = vocalI = vocalO = vocalU = 0;

      Scanner teclado = new Scanner(System.in);

      System.out.print("Introduzca un texto: ");
      String texto = teclado.nextLine();
      for(int i = 0; i < texto.length(); ++i) {
        switch(Character.toUpperCase(texto.charAt(i))) {
          case 'A':
            vocalA++;
            break;
          case 'E':
            vocalE++;
            break;
          case 'I':
            vocalI++;
            break;
          case 'O':
            vocalO++;
            break;
          case 'U':
            vocalU++;
            break;
          default:
            break;
        }
      }

      System.out.println("La vocal A aparece " + vocalA + " veces.");
      System.out.println("La vocal E aparece " + vocalE + " veces.");
      System.out.println("La vocal I aparece " + vocalI + " veces.");
      System.out.println("La vocal O aparece " + vocalO + " veces.");
      System.out.println("La vocal U aparece " + vocalU + " veces.");
    }
  }
