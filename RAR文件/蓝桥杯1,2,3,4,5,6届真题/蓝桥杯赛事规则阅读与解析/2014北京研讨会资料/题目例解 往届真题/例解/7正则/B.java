
// 《正则表达式必知必会》

public class B
{
	public static void main(String[] args)
	{
		String s = "11abc123kkk3456ttt576585";
		// 分离字母段和数字段
		s = s.replaceAll("([0-9])([a-z])","$1,$2");
		System.out.println(s);		
		
		s = s.replaceAll("([a-z])([0-9])","$1,$2");
		System.out.println(s);
		
	}
}