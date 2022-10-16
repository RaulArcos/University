  /**
   * Programa en Java que trabaja con cadenas
   * de la clase String y las invierte.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  public class InvertirCadena {
    public void escribeAlReves(String texto) {
      for(int i = texto.length()-1; i >= 0; i--) {
        System.out.print(texto.charAt(i));
      }
    }

    public static void main(String[] args) {
      String palindromo = "Dabale arroz a la zorra el abad";
      String quijote = "En un lugar de la Mancha ...";

      InvertirCadena ic = new InvertirCadena();

      System.out.println("Sin invertir:");
      System.out.println(palindromo);
      System.out.println(quijote);

      System.out.println("Al revés:");
      ic.escribeAlReves(palindromo);
      System.out.println();
      ic.escribeAlReves(quijote);
      System.out.println();
    }
  }
