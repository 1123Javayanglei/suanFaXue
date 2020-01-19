
/*
  �ο��𰸣�x.month-1

*/

#include "stdafx.h"

struct MyDate
{
	int year;
	int month;
	int day;
};

int GetAbsDays(MyDate x)
{
	int i;
	int month_day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year = x.year-1;  // ��Ϊ�������1��1��1�յľ���
	int days = year * 365 + year/4 - year/100 + year/400;
	if(x.year%4==0 && x.year%100!=0 || x.year%400==0) month_day[1]++;
	for(i=0; i<x.month-1; i++)
		days += month_day[i];
	days += x.day-1;
	return days;
}

int GetDiffDays(MyDate a, MyDate b)
{
	return GetAbsDays(b) - GetAbsDays(a);
}

int main(int argc, char* argv[])
{
	MyDate a = {1842,5,18};
	MyDate b = {2000,3,13};
	int n = GetDiffDays(a,b);
	printf("%d\n", n);

	return 0;
}

