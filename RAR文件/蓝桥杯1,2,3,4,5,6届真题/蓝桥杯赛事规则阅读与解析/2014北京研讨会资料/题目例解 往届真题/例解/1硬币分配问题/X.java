
public class X
{
	public static void main(String[] args)
	{
		int n = 50;  // Ӳ�Ҹ���
		int z = 20 * 100; //�ܱ�ֵ
		
		int k = 0;  // ��������
		
		for(int a=0; a<=50; a++)
		for(int b=0; b<=50; b++)
		for(int c=0; c<=50; c++)
		for(int d=0; d<=50; d++)
		{
			if(a+b+c+d==n && a*100+b*50+c*10+d*5==z) k++;
		}
		
		System.out.println(k);
	}
}