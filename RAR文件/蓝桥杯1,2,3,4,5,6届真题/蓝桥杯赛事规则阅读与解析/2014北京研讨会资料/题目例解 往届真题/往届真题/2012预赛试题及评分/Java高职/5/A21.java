

// ����һ�����г��ֵĵ�һ�����ֵ���ֵ
// ����Ҳ���������-1
// ac3y5  �򷵻�3

public class A21
{
	public static int getFirstNum(String s)
	{
		if(s==null || s.length()==0) return -1;
		
		char c = s.charAt(0);
		if(c>='0' && c<='9') return c-'0';  // ���1
		
		return getFirstNum(s.substring(1));  // ���2
	}
	
	public static void main(String[] args)
	{
		System.out.println(getFirstNum("ac1y5"));
		System.out.println(getFirstNum("2ac3y5"));
		System.out.println(getFirstNum("kkkacy3"));
		System.out.println(getFirstNum("abb"));
	}
}