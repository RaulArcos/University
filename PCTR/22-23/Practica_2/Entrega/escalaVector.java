/**
 * escalaVector.java hace el producto escalar de un vector de forma secuencial.
 * @author Raúl Arcos Herrera
 * @version 2022
 */
public class escalaVector {
    
    public static int[] v = new int[(int)Math.pow(10, 6)];
    /**
     * inicializar, recibe un vector y lo llena de valores int al azar.
     * @param v
     * @return un vector inicializado con valores ramdom.
     */
    public static int[] inicializar(int[] v){
        for(int i = 0; i < v.length; i++)
            v[i] = (int)(Math.random() * 10);
        return v;
    }
    public static void main(String[] args){
        v = inicializar(v);
        for(int i = 0; i < v.length ;i++)
            v[i] *= 3;
    }
}
