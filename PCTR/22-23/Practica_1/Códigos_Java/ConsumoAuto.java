  /**
   * Programa en Java que calcula el consumo medio de
   * un automóvil según 3 repostajes consecutivos.
   *
   * @author Natalia Partera
   * @version 1.0
   */

  import java.util.Scanner;

  public class ConsumoAuto {
    public static void main(String[] args) {
      double precioLitro, litros = 0;
      double pagado, coste = 0;
      int kmInicial, kmFinal, km;

      Scanner teclado = new Scanner(System.in);

      System.out.print("Introduzca el precio por litro del primer repostaje: ");
      precioLitro = teclado.nextDouble();
      System.out.print("Introduzca el coste total del primer repostaje: ");
      pagado = teclado.nextDouble();
      System.out.print("Introduzca el valor del cuentakilómetros en el primer repostaje: ");
      kmInicial = teclado.nextInt();
      litros = pagado / precioLitro;
      coste = pagado;

      System.out.println();
      System.out.print("Introduzca el precio por litro del segundo repostaje: ");
      precioLitro = teclado.nextDouble();
      System.out.print("Introduzca el coste total del segundo repostaje: ");
      pagado = teclado.nextDouble();
      litros += pagado / precioLitro;
      coste += pagado;

      System.out.println();
      System.out.print("Introduzca el valor del cuentakilómetros en el tercer repostaje: ");
      kmFinal = teclado.nextInt();
      km = kmFinal - kmInicial;

      System.out.println("El consumo medio del automóvil es de " + (litros / km * 100) + 
        " litros por cada 100 Km.");
      System.out.println("El gasto medio es de " + coste / km + " por kilómetro.");
    }
  }
