/**
 * @author Raúl Arcos Herrera
 * 
*/

import java.net.*;
import java.io.*;
public class clienteMultiple
{
    public static void main (String[] args)
    {
        int peticiones = Integer.parseInt(args[0]);

        try{

            for( int i = 0; i < peticiones; ++i )
        	{
        		int dato = (int)(Math.random()*10);
                System.out.println("Realizando conexion...");
                Socket cable = new Socket("10.142.101.22", 2001);
                System.out.println("Realizada conexion a "+cable);
                PrintWriter salida= new PrintWriter(
                                        new BufferedWriter(
                                            new OutputStreamWriter(
                cable.getOutputStream())));
                salida.println(dato);
                salida.flush();
                System.out.println("Cerrando conexion...");
                cable.close();
            }
        }//try
                catch (Exception e)
        {System.out.println("Error en sockets...");}
    }
}
	
