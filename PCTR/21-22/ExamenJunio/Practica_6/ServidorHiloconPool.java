/**
 * ServidorHilosconPool.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.net.*;
import java.io.*;

import java.util.concurrent.*;

public class ServidorHiloconPool implements Runnable{
    Socket enchufe;
    public ServidorHiloconPool (Socket s){
        this.enchufe = s;
    }

    public void run(){
        try{
            BufferedReader entrada = new BufferedReader(new InputStreamReader(enchufe.getInputStream()));
            String datos = entrada.readLine();
            int dato = Integer.parseInt(datos);

            int i = Integer.valueOf(datos).intValue();
            for(int j = 1; j <= 20; j++){
                System.out.println("El hilo "+Thread.currentThread()+" escribiendo el dato "+i);
                Thread.sleep(1000);
            }
            enchufe.close();
            System.out.println("El hilo "+Thread.currentThread()+"cierra su conexion...");
        } catch(Exception e) {System.out.println("Error...");}
    }

    public static void main (String[] args){
        int puerto = 2001;
        int tam = 1000;
        try{
            ServerSocket chuff = new ServerSocket (puerto, 3000);

            while (true){
                    
                ThreadPoolExecutor ept = new ThreadPoolExecutor(tam, tam, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>());
    
                System.out.println("[SERVIDOR] Creando nuevo pool...");
                for( int i = 0; i < tam; ++i )
                    ept.execute(new ServidorHiloconPool(chuff.accept()));
                System.out.println("[SERVIDOR] Pool completo...");
                ept.shutdown();
            }
        } catch (Exception e){System.out.println("Error en sockets...");}
    }
}
