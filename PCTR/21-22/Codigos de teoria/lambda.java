Runnable r = () -> System.out.println("Hello World!");
Thread th = new Thread(r);
th.start(); 