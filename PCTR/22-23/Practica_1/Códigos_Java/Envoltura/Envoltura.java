  public class Envoltura
  {
    public static void main (String[] args)
    {
      float s = 0;
      s = 10 / s;
      Float infinito = new Float(s);

      //Imprimirá "infinito es Infinity"
      System.out.println("infinito es " + infinito);
      Float noNumero = new Float(Math.sqrt(-1));
      //Imprimirá "noNumero es NaN"
      System.out.println("noNumero es " + noNumero);
    }
  }
