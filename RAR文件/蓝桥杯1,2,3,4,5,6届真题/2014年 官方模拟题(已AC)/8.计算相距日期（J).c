#include<stdio.h> 

int nian(int i)
{
			if((i%4==0&&i%100!=0)||i%400==0)
			return 366;
			else
			return 365;
}

int yue(int x,int y)
{
	if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)
	return 31;
	else if(x==4||x==6||x==9||x==11)
	return 30;
	else if(x==2&&y==0)
	return 28;
	else
	return 29;
}

main()
{
	int year,month,day;
	int st=0,num=0;
	int i;
	scanf("%d-%d-%d",&year,&month,&day);
	if(year>1949)
	{
		//���������������뿪ʼ��ݵ�����������������1955-10-25���˴�����1950��1954��������� 
		for(i=1950;i<year;i++)
		num+=nian(i);
		//�ж�������ݣ�1955���Ƿ�Ϊ���ꡣ�ǣ���ֵ��Ǳ���1������0�� 
		st=nian(year)==366?1:0;
//		printf("%d\n",st);//���� 
		//���������������·ݵ���������EX:�����10-25���˴�����1��9�µ������� 
		for(i=1;i<month;i++)
		num+=yue(i,st);
		//����1949��10��1�յ���ĩ�������� ���ۼ�10��1�յ��죩 
		for(i=10;i<=12;i++)
		num+=yue(i,0);
		//�����������1955��10�³���25�������������ۼӸ�num����ȥ1949��10��1������ 
		num+=day-1;
	}
	else if(year==1949)
	{
		//�������� 
		if(month>=10)
		{
			for(i=10;i<month;i++)
			num+=yue(i,0);
			num+=day-1;
		}
		else
		{
			for(i=month+1;i<10;i++)
			num+=yue(i,0);
			num+=day;
		}
	}
	else
	{
		//�������� 
		for(i=year+1;i<1949;i++)
		num+=nian(i);
		st=nian(year)==366?1:0;
		//EX������1948-1-3���˴�����2�³�������ĩ������ 
		for(i=month+1;i<=12;i++)
		num+=yue(i,st);
		//����1949��1��1�յ�9��ĩ��������û���ۼ�10��1�յ��죩 
		for(i=1;i<10;i++)
		num+=yue(i,0);
		//EX������1948-1-3���˴�����1��4�յ���ĩ������������1��3�յ��� 
		num+=yue(month,st)-day+1;
	}
	printf("%d\n",num);
}
