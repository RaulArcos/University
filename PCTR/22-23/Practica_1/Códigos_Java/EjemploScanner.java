  import java.util.Scanner;

  public class EjemploScanner {

    public static void main (String[] args) {
      byte by;
      short s;
      int i;
      long l;
      float f;
      double d;
      boolean b;

      //Se envuelve System.in en un objeto de clase Scanner
      Scanner Tec = new Scanner(System.in);

      System.out.println ("Introduzca: ");
      System.out.print ("Un byte ");
      by = Tec.nextByte();
      System.out.println("Byte: " + by);
      System.out.print ("Un short ");
      s = Tec.nextShort();
      System.out.println("Short: " + s);
      System.out.print ("Un int ");
      i = Tec.nextInt();
      System.out.println("Int: " + i);
      System.out.print ("Un long ");
      l = Tec.nextLong();
      System.out.println("Long: " + l);
      System.out.print ("Un float ");
      f = Tec.nextFloat();
      System.out.println("Float: " + f);
      System.out.print ("Un double ");
      d = Tec.nextDouble();
      System.out.println("Double: " + d);
    }
  }
