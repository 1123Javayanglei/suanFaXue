
import java.util.*;
import java.text.SimpleDateFormat;

public class A
{
	public static void main(String[] args) throws Exception
	{
		long t = new Date().getTime();
		System.out.println(t);
		
		Date d = new SimpleDateFormat("yyyy-MM-dd").parse("1997-07-01");
		
		long delta = (t - d.getTime())/(24L*60*60*1000);
		
		System.out.println(delta);
	}
}