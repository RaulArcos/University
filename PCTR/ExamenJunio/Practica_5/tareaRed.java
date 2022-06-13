import java.util.*;
import java.io.*;
import java.net.*;

public class tareaRed implements Runnable{
   
  private String dir;
  private URL url;
  private int j;
   	
  public tareaRed(String d, int i){dir=d; j=i;}
  
  public void run(){
    try{
         URL url = new URL(dir);
         BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
         FileWriter          f = new FileWriter(j+".html");
         BufferedWriter writer = new BufferedWriter(f);
         String line;
         while ((line = reader.readLine()) != null) {
            writer.write(line);
         }
         f.close();
         System.out.println(dir+" descargada...");
      }catch(IOException e){}
  }
}