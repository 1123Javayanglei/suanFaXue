
public class X
{
	// n��̨�ף���������¥������ÿ��1��2
	static int f(int n)
	{
		if(n==1) return 1;
		if(n==2) return 2;
		
		return f(n-1) + f(n-2);
	}
	
	public static void main(String[] args)
	{
		System.out.println(f(5));	
		//System.out.println(f(50));  //��cache	
	}
}