
/*
  a   b
  20  15
  
  15  20
  20  15
*/

public class A
{
	// ��a,b���Լ��
	static int gcd(int a, int b)
	{
		if(b==0) return a;
		return gcd(b,a%b);
	} 
	
	public static void main(String[] args)
	{
		System.out.println(gcd(20,15));	
		System.out.println(gcd(15,20));	
		
	}
}