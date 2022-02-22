public class redCajeros {
    public static void main(String[] args) throws Exception
    {
        cuentaCorriente cc  = new cuentaCorriente(1, 0.0);
        Runnable c1 = new cajero(cc, 100000.0, 1);
        Runnable c2 = new cajero(cc, 100000.0, 2);

        Thread  h1 = new Thread(c1);
        Thread  h2 = new Thread(c2);
         
        h1.start(); h2.start();
        h1.join(); h2.join();
         
        System.out.println("Saldo final = " + cc.saldo());
    }
}
