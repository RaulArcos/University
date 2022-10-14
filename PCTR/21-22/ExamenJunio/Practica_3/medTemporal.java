/**
 * @(#)medTemporal.java
 * @author A.T.
 * @version 2.00 2013/10/31
 * ESPECIFICACIONES: el programa ilustra el uso de los métodos  
 * necesarios para medir el tiempo de ejecución de un programa o de  
 * una tarea concreta. En este caso, se mide el tiempo que se tarda en  
 * ordenar un array de reales de precision doble con datos generados  
 * aleatoriamente.
 */

import java.util.*;
import java.text.*;

public class medTemporal
{
  public static double[] datos; //datos a ordenar
  public static int maxDim;     //permite fijar maxima  //dimension por teclado

  public static void main(String[] args)
  {
    System.out.println("Cuantos datos contendra el array?");
    Scanner s = new Scanner(System.in);
    maxDim    = s.nextInt();
    datos     = new double[maxDim];
    for(int i=0; i<maxDim; i++)datos[i]=Math.random(); 
    Date d = new Date();
    DateFormat df = new SimpleDateFormat("HH:mm:ss:SSS");
    long inicCronom = System.currentTimeMillis(); //se prepara el cronometro
    d.setTime(inicCronom); //se activa el cronometro
    System.out.println("Iniciando trabajo a las " + df.format(d));
    Arrays.sort(datos);   //se ordena el array de números
    long finCronom = System.currentTimeMillis(); //se para el cronometro
    d.setTime(finCronom);
    System.out.println("Acabando trabajo a las " + df.format(d) + " tras " + (finCronom - inicCronom) + " milisegundos");
    
  }//main
}//medTemporal
