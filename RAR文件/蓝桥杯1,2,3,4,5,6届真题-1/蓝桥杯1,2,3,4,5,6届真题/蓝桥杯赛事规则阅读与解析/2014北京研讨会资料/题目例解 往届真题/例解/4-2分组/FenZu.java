
import java.math.*;
import java.io.*;

public class FenZu
{	
	public static void main(String[] args) throws Exception
	{
		int people_num = 25;  // ��������
		final int track_num = 8;  //�ܵ���
		
		// ���������
		int group_num =  people_num / track_num;  
		if( people_num % track_num > 0 ) group_num++;
		
		int average_num = people_num / group_num; // ƽ��ÿ�������������ƣ�
		int remain = people_num % group_num; // ƽ����ÿ���ʣ������
		
		for(int i=0; i<group_num; i++)
		{
			if(i<remain)
				System.out.println(average_num+1);
			else
				System.out.println(average_num);
		}
	}
}
