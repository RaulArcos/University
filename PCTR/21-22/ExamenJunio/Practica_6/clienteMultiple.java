/**
 * clienteMultiple.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.net.*;
import java.io.*;

import java.util.concurrent.*;

public class clienteMultiple {
    public static void main (String[] args) throws Exception{
        int puerto = 2001;
        int peticiones = Integer.parseInt(args[0]);
        

        try{
            long iniciaC = 0, finC = 0;
            for (int i = 0; i < peticiones; i++){
                System.out.println("Realizando conexion...");
                Socket cable = new Socket("localhost", 2001);
                System.out.println("Realizada conexion a "+cable);

                //Manda un dato
                PrintWriter salida= new PrintWriter(
                                        new BufferedWriter(
                                            new OutputStreamWriter(
                cable.getOutputStream())));
                salida.println(i);
                salida.flush();
                
                //Recibe un dato
                BufferedReader entrada= new BufferedReader(
                                            new InputStreamReader(
                cable.getInputStream()));

                iniciaC = System.nanoTime();

                String in = entrada.readLine();

                finC = System.nanoTime();
                
                System.out.println("Cerrando conexion...");
                cable.close();
            }
            System.out.println("Tiempo de latencia: " + ((finC - iniciaC)/(long)1.0e9) + " ms para " + peticiones + "peticiones.");
        } catch (Exception e){System.out.println("Error en sockets...");}
    }
}
