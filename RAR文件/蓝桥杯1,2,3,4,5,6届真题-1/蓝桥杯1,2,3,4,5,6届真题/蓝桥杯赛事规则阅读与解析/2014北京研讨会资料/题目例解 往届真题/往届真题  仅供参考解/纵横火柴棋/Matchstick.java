
import java.util.*;
import java.io.*;

public class Matchstick
{
	private char[][] data;
	
	public Matchstick(char[][] data)
	{
		this.data = data;
	}
	
	// �жϷŷ��Ŀ�����
	private boolean isGoodStep(int i, int j, char c)
	{
		// ����Ϊ������
		if(data[i][j] != '0') return false;
		
		data[i][j] = c;
		try
		{
			String s = "";
			if(c=='1')
				s = s + data[0][j] + data[1][j] + data[2][j];
			else
				s = s + data[i][0] + data[i][1] + data[i][2] + data[i][3];
			
			s = s.replaceAll("0","");
			
			if(s.indexOf(""+c+c)>=0) return false;
		}
		finally
		{
			data[i][j] = '0';
		}
		
		return true;
	}
	
	// һ���Է�
	// �ڵ�i�У���j�� �Է� c
	// ��Ӯ���򷵻ش��ŷ������ܷ��û���˱����򷵻�null
	private String tryStep(int i, int j, char c)
	{
		if(isGoodStep(i,j,c))
		{
			data[i][j] = c;
			try
			{
				if(f()==null) return i + "," + j + "," + c;	
			}
			finally
			{
				data[i][j] = '0';
			}				
		}
		return null;
	}
	
	// ����data����
	// ������䣬����null
	// �����Ӯ�����ر�Ӯ���ŷ�֮һ
	public String f()
	{
		for(int i=0; i<3; i++)
		for(int j=0; j<4; j++)
		{
			String rt = null; 
			
			rt = tryStep(i,j,'1');
			if(rt!=null) return rt;
			
			rt = tryStep(i,j,'-');
			if(rt!=null) return rt;
		}
		return null;
	}
	
	private static char[][][] readData() throws IOException
	{
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.nextLine());
		char[][][] rt = new char[n][3][4];
		
		for(int k=0; k<n; k++)
		{
			for(int i=0; i<3; i++)
			{
				String s = scan.nextLine().trim();
				for(int j=0; j<4; j++)
					rt[k][i][j] = s.charAt(j);
			}
		}
		
		return rt;
	}
	
	static private void writeResult(String[] ss)
	{
		for(int i=0; i<ss.length; i++)
		{
			if(ss[i]==null)
				System.out.println("000");  // Ȩ��֮�ƣ�Ӧ��ѡ��ĳ�����е��߷�
			else
				System.out.println(ss[i].replaceAll(",",""));
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		// ����
		//char[][] a = {{'0','1','1','0'},{'-','0','0','0'},{'-','0','0','0'}};
		//char[][] a = {{'-','0','0','0'},{'0','0','0','0'},{'0','0','0','0'}};
		
		char[][][] a = readData();
		String[] b = new String[a.length]; 
		
		for(int i=0; i<a.length; i++)
		{
			b[i] = new Matchstick(a[i]).f();
		}
		
		writeResult(b);
	}
}