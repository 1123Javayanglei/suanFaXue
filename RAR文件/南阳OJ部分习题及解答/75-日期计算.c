/*
����
���⣬����һ�����ڣ���ʽ�磺2010 10 24 ���ж���һ������һ���еĵڼ��졣
����
��һ������һ����N��0<N<=100��,��ʾ��N��������ݡ������N����������������ݣ�ÿ�е��������ݶ���һ������ĿҪ���ʽ��������ڡ�
���
ÿ���������ݵ����ռһ�У�����жϳ�������n
��������
3
2000 4 5
2001 5 4
2010 10 24
�������
96
124
297
*/
#include <stdio.h>

int getDayOfYear(int year, int month, int day)
{
		int days[2][12]={{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
		int flag=(year%4==0&&year%100!=0)||year%400==0?0:1;
		int sum=day;
		int i;
		
		for(i=0;i<month;i++)	
		{
			sum+=days[flag][i];
		}
				
		return sum;		
}

main()
{
	int N;
	
	scanf("%d",&N);
	while(N--)
	{
		int year,month,day;
		
		scanf("%d%d%d",&year,&month,&day);
		printf("%d\n",getDayOfYear(year,month-1,day));
	}
	
	return 0; 
}
