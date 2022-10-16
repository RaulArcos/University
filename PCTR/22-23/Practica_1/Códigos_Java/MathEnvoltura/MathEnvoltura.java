  /**
   * Programa en Java que pide al usuario números
   * y realiza cálculos con ellos.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import java.util.Scanner;
  import static java.lang.Math.*;

  public class MathEnvoltura
  {
    public static void main (String[] args)
    {
      double x, y, z;

      Scanner teclado = new Scanner(System.in);

      System.out.print("Introduzca el primer número: ");
      x = teclado.nextDouble();
      Float xf = new Float(x);
      System.out.print("Introduzca el segundo número: ");
      y = teclado.nextDouble();
      Float yf = new Float(y);
      System.out.print("Introduzca el tercer número: ");
      z = teclado.nextDouble();
      Float zf = new Float(z);

      Float seno = new Float(sin(xf));
      System.out.println("El seno de " + xf + " es " + seno);
      Float coseno = new Float(cos(yf));
      System.out.println("El coseno de " + yf + " es " + coseno);
      Float tangente = new Float(tan(zf));
      System.out.println("La tangente de " + zf + " es " + tangente);
      
      System.out.println("El máximo entre " + xf + " y " + yf + " es " + max(xf, yf));
      System.out.println("El mínimo entre " + yf + " y " + zf + " es " + min(yf, zf));

      Float logaritmo = new Float(log(xf));
      System.out.println("El logaritmo neperiano de " + xf + " es " + logaritmo);
    }
  }
