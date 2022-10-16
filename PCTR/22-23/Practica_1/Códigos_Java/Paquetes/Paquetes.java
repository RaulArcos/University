  /**
   * Programa en Java que pide al usuario números
   * y realiza cálculos con ellos.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import java.util.Scanner;

  public class Paquetes
  {
    public static void main (String[] args)
    {
      double base, potencia;
      int exponente;
      double radicando, raiz;

      Scanner teclado = new Scanner(System.in);

      System.out.println("Introduzca los siguientes datos: ");
      System.out.print("Base: ");
      base = teclado.nextDouble();
      System.out.print("Exponente: ");
      exponente = teclado.nextInt();
      potencia = Math.pow(base, exponente);
      System.out.println(base + " elevado a " + exponente + " = " + potencia);
      System.out.print("Radicando: ");
      radicando = teclado.nextDouble();
      raiz = Math.sqrt(radicando);
      System.out.println("La raíz cuadrada de " + radicando + " es " + raiz);
    }
  }
