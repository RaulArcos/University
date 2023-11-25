/**
 * Usa_hebraSeguro.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 25/11/2021
 */

import java.util.Scanner;
import java.util.*;

public class Usa_hebraSeguro extends Thread{
    public static void main (String [] args) throws Exception {
        Object obj = new Object();

        hebraSeguro p = new hebraSeguro (1000000, 0, obj);
        hebraSeguro q = new hebraSeguro (1000000, 1, obj);

        p.start();
        q.start();
        p.join();
        q.join();
        
        System.out.println (hebraSeguro.n());
    }
}