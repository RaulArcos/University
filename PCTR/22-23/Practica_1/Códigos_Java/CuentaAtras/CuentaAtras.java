/**
 * Programa en Java que muestra una cuenta atrás
 * desde 5 hasta 0.
 *
 * @author Natalia Partera
 * @version 1.0
 */

public class CuentaAtras
{
  public static void main (String[] args)
  {
    int n = 5;

    System.out.println("Empieza la cuenta atrás: ");
    while (n >= 0)
    {
      System.out.println(n);
      --n;
    }
    System.out.println("Fin de la cuenta atrás.");
  }
}
