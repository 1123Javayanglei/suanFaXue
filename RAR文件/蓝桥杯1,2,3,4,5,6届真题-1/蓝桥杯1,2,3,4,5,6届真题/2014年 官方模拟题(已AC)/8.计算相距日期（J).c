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
		//计算除过输入年份与开始年份的总天数。假设输入1955-10-25，此处计算1950到1954年的总天数 
		for(i=1950;i<year;i++)
		num+=nian(i);
		//判断输入年份（1955）是否为闰年。是，则赋值标记变量1；否，则0。 
		st=nian(year)==366?1:0;
//		printf("%d\n",st);//测试 
		//计算该年除过输入月份的总天数。EX:输入的10-25，此处计算1到9月的总天数 
		for(i=1;i<month;i++)
		num+=yue(i,st);
		//计算1949年10月1日到年末的总天数 （累加10月1日当天） 
		for(i=10;i<=12;i++)
		num+=yue(i,0);
		//计算输入年份1955年10月初到25日天数，将其累加给num并减去1949年10月1日那天 
		num+=day-1;
	}
	else if(year==1949)
	{
		//与上类似 
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
		//与上类似 
		for(i=year+1;i<1949;i++)
		num+=nian(i);
		st=nian(year)==366?1:0;
		//EX：输入1948-1-3，此处计算2月初到该年末总天数 
		for(i=month+1;i<=12;i++)
		num+=yue(i,st);
		//计算1949年1月1日到9月末总天数（没有累加10月1日当天） 
		for(i=1;i<10;i++)
		num+=yue(i,0);
		//EX：输入1948-1-3，此处计算1月4日到月末的天数并加上1月3日当天 
		num+=yue(month,st)-day+1;
	}
	printf("%d\n",num);
}
