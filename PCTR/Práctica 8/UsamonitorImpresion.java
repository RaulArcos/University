/**
 * @author Raúl Arcos Herrera
 */
public class UsamonitorImpresion extends Thread
{
    public static int n = 0;
    public monitorImpresion monImp;
  
    public UsamonitorImpresion(monitorImpresion monitorImpresion){this.monImp=monitorImpresion;}
  
    public void run(){
        int impUso;
        for(int i=0; i<100; i++)
        {
            impUso = monImp.take_print();
            System.out.println("El Thread: "+ Thread.currentThread().getName() +" UTILIZA la impresora: " + impUso);
            monImp.drop_print(impUso);
            System.out.println("El Thread: "+ Thread.currentThread().getName() +" DEVUELVE la impresora: " + impUso);
        }
    }
  
    public static void main(String[] args) throws Exception{
      monitorImpresion mon_imp = new monitorImpresion(2);
      UsamonitorImpresion A = new UsamonitorImpresion(mon_imp);  
      UsamonitorImpresion B = new UsamonitorImpresion(mon_imp);
      UsamonitorImpresion C = new UsamonitorImpresion(mon_imp);
      A.start(); B.start(); C.start();
      A.join(); B.join(); C.join();
    }
    
}
