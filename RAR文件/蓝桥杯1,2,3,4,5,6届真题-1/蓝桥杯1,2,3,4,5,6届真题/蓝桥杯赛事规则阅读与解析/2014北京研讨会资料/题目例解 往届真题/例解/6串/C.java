
public class C
{
	static String f(String x)
	{
		if(x.length()<2) return x;
		
		return f(x.substring(1)) + x.charAt(0);
	}
	
	public static void main(String[] args)
	{
		String s = "1234567";
		
		System.out.println(f(s));
		
		//String s2 = "";
		//for(int i=s.length()-1; i>=0; i--)  s2 = s2 + s.charAt(i);
		//for(int i=0; i<s.length(); i++) s2 = s.charAt(i) + s2;
		
		//System.out.println(s2);
	}
}