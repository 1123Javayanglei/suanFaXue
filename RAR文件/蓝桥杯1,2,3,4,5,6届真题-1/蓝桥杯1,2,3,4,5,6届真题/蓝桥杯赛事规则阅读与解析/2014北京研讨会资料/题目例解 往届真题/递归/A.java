
/*
  1. Ѱ�������ԣ��Ա���Ƥ��
  2. ���조���ڡ�
  
  3. û�������ԣ����Ӳ�������
  
  4. ƽ�������
  5. ������У������̵�ѵ���� haskell cheatsheet
  
  6. Ч�����⣺�����壬��ֹ�ظ�����
  
*/

public class A
{
	// ��ӡ�� 0 �� n
	static void f(int n)
	{
		if(n<0) return;
		//if(n>0) f(n-1);
		f(n-1);
		System.out.println(n);
	}


	// ��ӡ��a��b
	static void g(int a, int b)
	{
		if(a>b) return;
		System.out.println(a);
		g(a+1,b);
	}
	
	// m������ȡn��������ȡ����
	static int h(int m, int n)
	{
		//System.out.println(m + "," + n);
		if(m<n) return 0;
		if(m==n) return 1;
		if(n==0) return 1;
		
		return h(m-1,n-1) + h(m-1,n);
	}
	
	public static void main(String[] args)
	{
		int n = h(5,3);
		System.out.println(n);

		
		
		//�ݹ�˼��
		// ��Ƥ��  ����ת�� ...
		
		//for(int i=0; i<10; i++) System.out.println(i);
		//��дѭ��
		//f(9);
		
		//g(0,9);
		
	}
}