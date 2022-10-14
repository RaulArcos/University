/**
 * prodEscalar.java
 * @author Maria Teresa Supervielle Sanchez
 * @version 05/11/2021
 */

public class prodEscalar{  
    public static int v1[] = new int [(int)Math.pow(10, 6)];
    public static int v2[] = new int [(int)Math.pow(10, 6)];

    /**
     * Main
     */
    public static void main(String[] args) {
        int productoEscalar = 0;

        long inicioC = System.currentTimeMillis();

        for (int i = 0; i < (int)Math.pow(10, 6); i++){
            v1[i] = i;
            v2[i] = i;
            productoEscalar = productoEscalar + (v1[i] * v2[i]);
        }

        long finC = System.currentTimeMillis();
        System.out.println((finC - inicioC) + " ms");
    }
}
