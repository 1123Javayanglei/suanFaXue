
// ģ����ʵ���߼��ȼۼ���

import java.util.*;

public class X
{
	// n���˳���������ͬ����
	static double f(int n)
	{
		final int W = 1000 * 100;  //�ܵ�ʵ�����
		
		int w = 0; // ������ͬ���յĴ���
		for(int i=0; i<W; i++)
		{
			Set set = new HashSet();
			for(int j=0; j<n; j++)
			{
				int r = (int)(Math.random() * 365);	 // ���������
				set.add(r);
			}
			
			if(set.size()<n) w++;
		}
		
		return 1.0 * w / W;
	}
	
	public static void main(String[] args)
	{
		System.out.println(f(30));	
	}
}