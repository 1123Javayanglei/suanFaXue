


public class A
{	
	static int f(String s)
	{
		if(s.length()==0) return 0;
		
		if(s.charAt(0)=='C'){
			if(s.indexOf('M')>0 || s.indexOf('D')>0)
				return -100 + f(s.substring(1));
			else
				return 100 + f(s.substring(1));
		}

		if(s.charAt(0)=='X'){
			if(s.indexOf('C')>0 || s.indexOf('L')>0)
				return -10 + f(s.substring(1));
			else
				return 10 + f(s.substring(1));
		}
		
		if(s.charAt(0)=='I'){
			if(s.indexOf('X')>0 || s.indexOf('V')>0)
				return -1 + f(s.substring(1));
			else
				return 1 + f(s.substring(1));
		}		
		
		if(s.charAt(0)=='M') return 1000 + f(s.substring(1));
		if(s.charAt(0)=='D') return 500 + f(s.substring(1));
		if(s.charAt(0)=='L') return 50 + f(s.substring(1));
		if(s.charAt(0)=='V') return 5 + f(s.substring(1));
		
		return 0;
	}
	
	public static void main(String[] args)
	{
		/*
		String s = "abcdakdsfdsfe";
		for(int i=0; i<s.length(); i++)
		{
			char x = s.charAt(i);
			if(s.lastIndexOf(x)!=i) System.out.println("!!");
		}
		*/
		
		/*
		String s = "abcde";
		String s2 = "";
		for(int i=0; i<s.length(); i++) s2 = s.charAt(i) + s2;
		System.out.println(s2);
		*/
		
		System.out.println(f("XXXIX"));
		
		// 串的翻转
		// 求是否包含重复字母
		// 串与数字间转化 进制 罗马 小数
	}
}