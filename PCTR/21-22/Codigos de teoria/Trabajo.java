import java.util.*;
import java.text.*;

public class Trabajo implements Runnable {
	long n;
	String id;

	private long fib(long n) {
		if (n == 0) return 0L;
		if (n == 1) return 1L;

		return fib(n - 1) + fib(n - 2);
	}

	public Trabajo(long n, String id) {
		this.n = n;
		this.id = id;
	}

	
	
	public void run() {
		Date d = new Date();
		DateFormat df = new SimpleDateFormat("HH:mm:ss:SSS");
		long startTime = System.currentTimeMillis();
		d.setTime(startTime);
		System.out.println("Iniciando trabajo " + id + " a las " + df.format(d));

		fib(n);

		long endTime = System.currentTimeMillis();
		d.setTime(endTime);
		System.out.println("Acabando trabajo " + id + " a las " + df.format(d) + " tras " + (endTime - startTime) + " milliseconds");
	}
}