/**
 * @author Raúl Arcos Herrera
 * 
*/

import java.net.*;
import java.io.*;
import java.util.concurrent.*;

public class ServidorHiloconPool implements Runnable
{
	Socket enchufe;
    public ServidorHiloconPool(Socket s)
    {enchufe = s; this.start();}

    public void run()
    {
    try{
        BufferedReader entrada = new BufferedReader(
                                    new InputStreamReader(
                                        enchufe.getInputStream()));
        String datos = entrada.readLine();
        int j;
        int i = Integer.valueOf(datos).intValue();
        for(j=1; j<=20; j++){
        System.out.println("El hilo "+this.getName()+" escribiendo el dato "+i);
        sleep(1000);}
        enchufe.close();
        System.out.println("El hilo "+this.getName()+"cierra su conexion...");
    } catch(Exception e) {System.out.println("Error...");}
    }//run

public static void main (String[] args)
{
    int tam = 10000;
        
    try{
            ServerSocket chuff = new ServerSocket (2001, 3000);

            while (true){
                ThreadPoolExecutor ept = new ThreadPoolExecutor(tam, tam, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());
				ept.prestartAllCoreThreads();
	
				System.out.println("Creando nuevo pool");
				for( int i = 0; i < tam; ++i )
					ept.execute(new ServidorHiloconPool(chuff.accept()));
				System.out.println("Pool completo");
				ept.shutdown();
	
				boolean fin = false;
				while( !fin )	//Espera hasta que terminen todas las tareas
					try
					{
						fin = ept.awaitTermination(20, TimeUnit.SECONDS);
					} catch( InterruptedException e) {}
        }//while
      } catch (Exception e)
        {System.out.println("Error en sockets...");}
    }
}
