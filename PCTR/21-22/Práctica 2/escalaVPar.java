public class escalaVPar {
    
    public static int[] v = new int[1000*(int)Math.pow(10, 6)];
    
    public static int[] inicializar(int[] v)
    {
        for(int i = 0; i < v.length; i++)
        {
            v[i] = (int)(Math.random() * 10);
        }
        return v;
    }

    //THREAD
    /*
    public static void main(String[] args) throws Exception
    {   
        //Se divide el vector en 2 tareas.
        Thread h1 = new hilo(0,v.length/2,v,3);
        Thread h2 = new hilo(v.length/2,v.length,v,3);
		long inicTiempo = System.nanoTime();
		h1.start(); h2.start();
		h1.join(); h2.join();
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("Terminado en " + tiempoTotal + " ms");
    }
    */
    //RUNNABLE
    
    public static void main(String[] args) throws Exception
    {  
        //Se divide el vector en 2 tareas.
        tarea t1 = new tarea(0,v.length/2,v,3);
        tarea t2 = new tarea(v.length/2,v.length,v,3);

        Thread h1 = new Thread(t1);
        Thread h2 = new Thread(t2);
        long inicTiempo = System.nanoTime();
        h1.start(); h2.start();
        h1.join(); h2.join();
        long tiempoTotal = (System.nanoTime()-inicTiempo)/(long)1.0e6;
        System.out.println("Terminado en " + tiempoTotal + " ms");
    }
    
}

class hilo extends Thread
{
    public final int ini;
    public final int fin;
    public int[] vector;
    public final int escalar;

    public hilo(int i, int f, int[] v, int e)
    {
        ini = i;
        fin = f;
        vector = v;
        escalar = e;
    }

    public void run() 
    {
        for(int i = ini; i < fin; ++i)  vector[i] *= escalar;
    }
}   

class tarea implements Runnable
{
    public final int ini;
    public final int fin;
    public int[] vector;
    public final int escalar;

    public tarea(int i, int f, int[] v, int e)
    {
        ini = i;
        fin = f;
        vector = v;
        escalar = e;
    }

    public void run() 
    {
        for(int i = ini; i < fin; ++i)  vector[i] *= escalar;
    }
} 