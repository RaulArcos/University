import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.*;
import java.util.concurrent.Semaphore;

public class ExclusionMutua {

    //----------------------------------CERROJOS REENTRANTES----------------------------------
    //dentro de la clase
        public ReentrantLock lock = new ReentrantLock();

    //Funcion utilizando semaforos reentrantes
        public double ingresar (double n) { 
            lock.lock();
            try {
                //SC
            } finally {lock.unlock();}
        }

    //----------------------------------CERROJOS----------------------------------
    //dentro de la clase
        final ReentrantLock lock = new ReentrantLock();
        final Condition semZero = lock.newCondition();

    //Funcion utilizando cerrojos y condiciones de guarda
        public void waitS() throws InterruptedException{
            lock.lock();
            try{
            while(/*Condicion*/) semZero.await(); //await espera, signalAll()
                //SC
            }finally {lock.unlock();}
        }

        public void signalS() throws InterruptedException{
            //SC
            notifyAll();
        }
    
    //----------------------------------SEMAFORO----------------------------------
    //dentro de la clase
        public Semaphore sem = new Semaphore(1); //1 solo semaforo

    //Funcion utilizan semaforos
        public double ingresar (double n) { 
            try {
                //SC
            } finally {sem.release();}
        }

    //----------------------------------SYNCHRONIZED----------------------------------
    //dentro de la clase
        private Object obj; //en el constructor tendriamos que asignar el mismo objeto a todos los hilos

        public void run() { 
            //Objeto seguro 
            synchronized(obj){  
                //SC
            }
        
    //dentro del main
        Object obj = new Object(); //se pasa al constructor
    } 

    //---------------------------------------------------------------------------------------------
    //---------------------------------------------CPP---------------------------------------------
    //---------------------------------------------------------------------------------------------

    class Clase_cpp {
        mutex em; //Exclusion mutua
        condition_variable cv;
           
        unique_lock <mutex> lck{em}; //cerrojo
            
        cv.wait(lck); //Espera
        cv.notify_all(); //Notifica
    
    
        Clase_cpp cpp;
        thread personas[200]; //vector de hilos
        
        for (unsigned i = 0; i < 200; ++i) personas[i] = thread{playa, ref(cpp)}; //funcion (donde se maneja el monitor, el run en java), referencia a un objeto de la clase
        for (unsigned i = 0; i < 200; ++i) personas[i].join();
    }
}
