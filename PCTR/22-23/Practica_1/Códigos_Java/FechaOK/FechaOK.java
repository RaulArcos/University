/**
 * Programa en Java que pide al usuario el día, mes y año
 * de una fecha e indica si es una fecha válida.
 *
 * @author Natalia Partera
 * @version 1.0
 */

import java.util.Scanner;

public class FechaOK
{
  public boolean esFechaOK (int dia, int mes, int año) {
    int diasMes;

    //Se comprueba que el mes es correcto.
    if (mes < 1 || mes > 12)
      return false;
    if (año < 1600 || año > 3000)
      return false;

    //Es un mes correcto, se calcula los días que tiene.
    switch (mes) {
      case 4:
      case 6:
      case 9:
      case 11:
        diasMes = 30;
        break;
      case 2:
        if ((año % 4 == 0) && (año % 100 != 0) || (año % 400 == 0)) {
          diasMes = 29;
        }
        else {
          diasMes = 28;
        }
        break;
      default:
        diasMes = 31;
        break;
    }

    //Se comprueba que el día es correcto.
    return dia >= 1 && dia <= diasMes;
  }

  public static void main (String[] args)
  {
    int dia, mes, año;
    FechaOK f = new FechaOK();

    Scanner teclado = new Scanner(System.in);

    System.out.print("Introduzca el día: ");
    dia = teclado.nextInt();
    System.out.print("Introduzca el mes: ");
    mes = teclado.nextInt();
    System.out.print("Introduzca el año: ");
    año = teclado.nextInt();
    if (f.esFechaOK(dia, mes, año))
      System.out.println("La fecha es correcta.");
    else
      System.out.println("La fecha es incorrecta.");
  }
}
