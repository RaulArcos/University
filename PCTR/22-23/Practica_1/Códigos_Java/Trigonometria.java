  /**
   * Programa en Java que realiza cálculos trigonométricos.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import static java.lang.Math.*;

  public class Trigonometria
  {
    void funciones(double alfa) {
      System.out.println(toDegrees(alfa) + " " + sin(alfa) + " " + cos(alfa) + " " + 
        tan(alfa));
    }

    public static void main (String[] args)
    {
      Trigonometria trig = new Trigonometria();

      trig.funciones(0);
      trig.funciones(PI / 4);
      trig.funciones(PI / 2);
      trig.funciones(PI);
    }
  }
