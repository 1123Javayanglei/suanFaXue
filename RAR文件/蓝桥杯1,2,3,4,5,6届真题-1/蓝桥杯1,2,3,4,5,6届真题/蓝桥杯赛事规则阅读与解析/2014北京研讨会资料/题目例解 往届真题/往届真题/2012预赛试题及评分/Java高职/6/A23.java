
// �˿��� A,2,3,4,5,6,7,8,9,10,J,Q,K
// ��ǰ������һ�ŷŵ�����
// �ٴ�ǰ������һ���Ʒ����ϣ��ظ���ֱ��ʣ�����һ���ƣ������ϡ�
// 

import java.util.*;

public class A23
{
	public static List moveCard(List src)
	{
		if(src==null) return null;
		
		List dst = new Vector();
		for(;;)
		{
			if(src.size()==0) break;  // ���1
			src.add(src.remove(0));
			dst.add(src.remove(0));  // ���2
		}
		
		return dst;
	}
	
	public static void main(String[] args)
	{
		List a = new Vector();
		a.addAll(Arrays.asList("A","2","3","4","5","6","7","8","9","10","J","Q","K"));
		System.out.println(moveCard(a));
	}
}