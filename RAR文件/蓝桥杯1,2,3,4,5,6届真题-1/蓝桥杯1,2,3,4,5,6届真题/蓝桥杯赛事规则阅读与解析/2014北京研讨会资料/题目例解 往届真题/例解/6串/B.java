
// ����ʽ��˼·

public class B
{
	static int f(String x)
	{
		int sum = 0;
		
		for(int i=0; i<x.length(); i++){
			char c = x.charAt(i);
			if(c=='I') sum += 1;
			if(c=='V') sum += 5;
			if(c=='X') sum += 10;
			// ....
		}
		
		// һ���е��º���
		if(x.indexOf("IX")>=0) sum -= 2;
		// .....
		

		
		return sum;
	}
	
	public static void main(String[] args)
	{
		System.out.println(f("XII"));
		System.out.println(f("IX"));
	}
}