
public class X
{
	// ������ȡ����ʣ��n����ʱ����ȡ������Ӯ��
	static boolean f(int n)
	{
		if(n==1) return false;
		
		if(n>1 && f(n-1)==false) return true;
		if(n>3 && f(n-3)==false) return true; 
		if(n>7 && f(n-7)==false) return true;
		if(n>8 && f(n-8)==false) return true;
		 
		return false;
	}
	
	public static void main(String[] args)
	{
		System.out.println(f(14));  // �Ż�ʱ����Ҫ������
	}
}