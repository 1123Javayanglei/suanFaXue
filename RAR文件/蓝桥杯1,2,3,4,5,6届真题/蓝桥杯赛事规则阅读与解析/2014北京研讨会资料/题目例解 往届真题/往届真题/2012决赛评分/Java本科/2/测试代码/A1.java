
// �����(�������)����Գ��Ӵ�
public class A1
{
	public static String getMaxMirrorString(String s)
	{
		String max_s = "";  // ��������Գ��Ӵ�
	
		for(int i=0; i<s.length(); i++)
		{
			// ��һ�ֶԳ�ģʽ
			int step = 1;
			try{
				for(;;)
				{
					if(s.charAt(i-step) != s.charAt(i+step)) break;
					step++;
				}
			}catch(Exception e){}
			
			String s1 = s.substring(i-step+1,i+step);  // ���1
			
			
			// �ڶ��ֶԳ�ģʽ
			step = 0;
			try{
				for(;;)
				{
					if(s.charAt(i-step) != s.charAt(i+step+1)) break;  // ���2
					step++;
				}
			}catch(Exception e){}
			
			String s2 = s.substring(i-step+1,i+step+1);
			
			
			if(s1.length() > max_s.length()) max_s = s1;
			if(s2.length() > max_s.length()) max_s = s2;
		}
		
		return max_s;				
	}
	
	public static void main(String[] args)
	{		
		System.out.println(getMaxMirrorString("abcdeefghhgfeiieje444k444lmn"));
	}
}