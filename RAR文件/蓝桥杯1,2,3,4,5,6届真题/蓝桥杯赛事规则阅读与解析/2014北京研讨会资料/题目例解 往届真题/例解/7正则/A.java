
public class A
{
	public static void main(String[] args)
	{
		//String s = "abc1234xyz888kkkkk";	
		//s = s.replaceAll("([0-9]+)","$1,");
		//s = s.replaceAll("([a-z]+)","$1,");
		String s = "afkdjsakfjsd 2003-1-19 ljfkdsfsdhghadsaf";
		s = s.replaceAll("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})", "$2/$3/$1");
		
		System.out.println(s);
		
		//String s = "abc,xyz,kkkk";
		//String s = "abc+xyz+kkkk";		
		//String[] ss = s.split("\\+");
		
		//String s = "abc1234xyz888kkkkk";
		//String[] ss = s.split("[0-9]+");
		//String[] ss = s.split("[a-zA-Z]+");
		
		//for(int i=0; i<ss.length; i++){
		//	System.out.println(ss[i]);
		//}
	}
}