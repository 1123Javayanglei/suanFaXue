
public class A
{
	// n ��̨�ף�������
	static int g(int n)
	{
		if(n==1) return 1;
		if(n==2) return 1;
		
		return f(n-1) + f(n-2);
	}
	
	// n ��̨�ף�ż����
	static int f(int n)
	{
		if(n==1) return 0;
		if(n==2) return 1;
		//if(n==3) return 2;
		
		return g(n-1) + g(n-2);
	}
	
	public static void main(String[] args)
	{
		System.out.println(f(39));
	}
}