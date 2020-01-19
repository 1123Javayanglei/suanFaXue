
// 四则运算表达式的正则解法
//  2 + 3 * (5-4) * 6

import java.util.regex.*;

public class A
{
	// 计算没有括号的表达式
	public static int f(String s)
	{
		// [0-9] = [0123456789] = 0|1|2|3|4|....
		for(;;)
		{
			Matcher m = Pattern.compile("([0-9]+)\\*([0-9]+)").matcher(s);
			if(!m.find()) break;
			
			s = s.replace(m.group(), 
				Integer.parseInt(m.group(1)) * Integer.parseInt(m.group(2))+"");
		}
		
		for(;;)
		{
			Matcher m = Pattern.compile("([0-9]+)\\+([0-9]+)").matcher(s);
			if(!m.find()) break;
			
			s = s.replace(m.group(), 
				Integer.parseInt(m.group(1)) + Integer.parseInt(m.group(2))+"");
		}		
		
		return Integer.parseInt(s);		
	}
	
	public static void main(String[] args)
	{
		String s = "2*(3+5*2+(3+8)*(4+2))+(4+5*3)";
		
		// 不断去掉最内层括号		
		for(;;)
		{
			Matcher m = Pattern.compile("\\(([^\\(\\)]+)\\)").matcher(s);
			if(!m.find()) break;
			
			s = s.replace( m.group(), f(m.group(1))+"" );  // 不能用replaceAll等
			//System.out.println(m.group());
		}
		
		System.out.println(f(s));	
	}
}