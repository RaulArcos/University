import java.util.*;
import java.io.*;
import java.net.*;

public class volcadoRedSecuencial{

  public static void descargar(String dir, int i){
      try{
         URL url = new URL(dir);
         BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
          FileWriter          f = new FileWriter(i+".html");
         BufferedWriter writer = new BufferedWriter(f);
         String line;
         while ((line = reader.readLine()) != null){writer.write(line);}
         f.close();
         System.out.println(dir+" descargada...");
      }catch(IOException e){}
   } 
  
  public static void main(String[] args){

    int cont=0;
    long iniTiempo = System.nanoTime();	  
    try {
    	 String linea=" ";      
    	 RandomAccessFile direcciones = new RandomAccessFile("direccionesRed.txt","r");
         while(linea!=null){
           linea =(String)direcciones.readLine();
           if(linea!=null)descargar(linea, cont);
           cont++;
         }
         direcciones.close();
        }catch (FileNotFoundException e) {}
         catch (IOException e) {}
    long finTiempo = System.nanoTime();
    System.out.println("Tiempo Total (segundos): "+(finTiempo-iniTiempo)/1.0e9);
  }  
}
