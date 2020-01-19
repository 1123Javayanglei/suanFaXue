
// 详细遍历匹配的模式信息

import java.util.regex.*;
public class A
{
	public static void main(String[] args)
	{
		String s = "aaabb ddd  2012/05/16 bb  cc 2011/5/3 ttmm 1988/12/05 cc 1977/7/";
		
		Pattern p = Pattern.compile("([0-9]{4})/([0-9]{1,2})/([0-9]{1,2})");
		Matcher m = p.matcher(s);
		
		while(m.find())
		{
			System.out.println(m.group() + "," 
				+ m.group(1) + "," + m.group(2) + "," + m.group(3)  
				+ " at: " + m.start() + "," + m.end());
		}
		
	}
}