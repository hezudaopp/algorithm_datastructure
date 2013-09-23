
class Test {
	public static int k=0;
	public static Test t1 = new Test("t1");
	public static Test t2 = new Test("t2");
	{
		System.out.println("Struct block");
	}
	static {
		System.out.println("Static block");
	}
	public Test (String s) {
		print(s);
	}
	public static void print(String s) {
		System.out.println(s);
	}

	public static void main (String ...s) {
		Test t = new Test("init");
	}
}