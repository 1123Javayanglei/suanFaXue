
/*
  �����ԣ�
     �������Ӳ���
  ����
*/

public class X
{	
	static int N = 0;  // ��¼����

	// ö��a���������У���ǰö���±꣺k
	static void f(int a[], int k)
	{
		if(k==a.length-1)
		{
			int x = a[0]*100 + a[1]*10 + a[2];
			int y = a[3]*100 + a[4]*10 + a[5];
			int z = a[6]*100 + a[7]*10 + a[8]; 
			
			if(x+y==z) N++;
			return;
		}
		
		//�оٵ�kλ�����������������
		for(int i=k; i<a.length; i++)
		{
			{int t=a[k]; a[k]=a[i]; a[i]=t;}  //����
			f(a, k+1);
			{int t=a[k]; a[k]=a[i]; a[i]=t;}  //����,����  ����
		}
	}
	
	public static void main(String[] args)
	{
		int[] a = {1,2,3,4,5,6,7,8,9};
		
		f(a,0);
		System.out.println(N);
	}
}