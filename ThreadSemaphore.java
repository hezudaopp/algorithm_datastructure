import java.util.concurrent.Semaphore;

public class ThreadSemaphore extends Thread {

	static Runnable runnerA = new Runnable() {
		public void run () {
			System.out.println("A");
		}
	};

	static Runnable runnerB = new Runnable() {
		public void run () {
			System.out.println("B");
		}
	};

	static Runnable runnerC = new Runnable() {
		public void run () {
			System.out.println("C");
		}
	};

	public void run() { // override Thread's run()
        System.out.println("Here is the starting point of Thread.");
        for (;;) { // infinite loop to print message
            System.out.println("User Created Thread");
        }
    }

	public static void main (String[] args) {
		Thread t = new ThreadSemaphore();
        t.start();
		Thread ta = new Thread(runnerA, "t_a");
		Thread tb = new Thread(runnerB, "t_b");
		Thread tc = new Thread(runnerC, "t_c");
		ta.start();
		tb.start();
		tc.start();
	}
}