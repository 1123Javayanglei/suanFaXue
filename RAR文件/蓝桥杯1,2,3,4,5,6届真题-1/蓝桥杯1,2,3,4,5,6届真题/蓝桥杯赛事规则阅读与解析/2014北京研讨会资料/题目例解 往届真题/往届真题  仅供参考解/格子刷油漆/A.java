
public class A
{
	//��ĳ��������ӿ�ʼ���������ں������ڵ���һ��������ӵ��������
	static int fb(int n)
	{
		if(n==1) return 1;
		return fb(n-1) * 2;
	}
	
	//��ĳ��������ӿ�ʼ���������
	static int fa(int n)
	{
		if(n==1) return 1;
		if(n==2) return 6;
		return 2 * fa(n-1) + 4 * fa(n-2) + fb(n);
	}
	
	// ��ĳ���ǽ���ĸ��ӿ�ʼ���������
	static int fk(int i, int n)
	{
		return fb(i) * fa(n-i) * 2 * 2;
	}
	
	static int f(int n)
	{
		if(n==1) return 2;
		
		int sum = fa(n) * 4;
		for(int i=2; i<n; i++){
			sum += fk(i,n) * 2;
		}
		return sum;
	}
	
	public static void main(String[] args)
	{
		for(int i=1; i<15; i++){
			System.out.println(i + ": " + f(i));	
		}
	}
}