Runnable r = new Runnable() {
   @Override
   public void run() {
	System.out.println("Hello World!");
   }
};
Thread th = new Thread(r);
th.start(); 