
class Test {
	public static int k=0;
	public static Test t1;
	public static Test t2 = new Test("t2");	// Struct block and Structure function
	// public Test t3 = new Test("t3");	//dead loop
	// System.out.println("before structure function");
	{
		System.out.println("Struct block");	// this block will be executed only before structure function
	}
	static {
		System.out.println("Static block");	// this block will be executed for only once time (When Class being loaded).
	}
	public Test (String s) {
		print(s);
	}
	public static void print(String s) {
		System.out.println(s);
	}

	public static void main (String ...s) {
		Test t = new Test("init");
		Test t4;	// No thing will be displayed.
	}
}