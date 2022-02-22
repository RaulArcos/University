public class escalaVector {
    
    public static int[] v = new int[(int)Math.pow(10, 6)];

    //Inicializamos el vector con valores random.
    public static int[] inicializar(int[] v)
    {
        for(int i = 0; i < v.length; i++)
        {
            v[i] = (int)(Math.random() * 10);
        }
        return v;
    }

    public static void main(String[] args)
    {
        v = inicializar(v);

        for(int i = 0; i < v.length ;i++)
        {
            v[i] *= 3;
        }
    }
}
