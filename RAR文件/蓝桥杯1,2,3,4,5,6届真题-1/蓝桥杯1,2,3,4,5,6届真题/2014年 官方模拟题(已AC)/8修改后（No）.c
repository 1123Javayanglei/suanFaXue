//最会一道题


#include <stdio.h>
int record[5];
int counts;

void fun(int *s, int n, int count, int a)
{   int i,k, sum = 0;
	for(i = 0; i < 5; i++)
	{
		if(s[i] > n)
			break;
	}
	k = i;
	//计算比n小的数的和
	while(--k >= 0)
	{   
		sum += s[k];
	}
	//假如sum刚等于n，这输出,并中断
	if(n == sum)
	{
		k = i;
		while(--k >= 0)
		{   if(a == 1)
				record[count++] = s[k]; 
			else 
				record[count++] = -s[k];
		}
		return;
	}
	//假如sum小于n则取刚大于n的第一个值
	if(sum < n)
	{
		if(a == 1)
			record[count++] = s[i]; 
		else 
			record[count++] = -s[i];
		n = s[i] - n; 
		//********************************变化a的值来确定正负
		a *= -1;				//有机会想想
		fun(s, n, count, a);
	}
	//假如sum大于n则取刚小于n的第一个值
	else if(sum > n)
	{
		if(a == 1)
			record[count++] = s[i-1]; 
		else 
			record[count++] = -s[i-1];
		n = n - s[i-1];
		//***************************************变化a的值来确定正负
		a *= 1;                  //有机会想想
		fun(s, n, count, a);
	}

	
}













main()
{
	int s[5] = {1, 3, 9, 27, 81};
	int n,result;
	int aa = 1;            //表示数字存储的正1默认正  1 +， -1 -
	int *p = record;
	counts = 0;
	printf("亲输入一个1—121之间的数:");
	scanf("%d",&n);
	result=n;
	fun(s, n, counts, aa);
	printf(" %d",record[0]);
	for(n = 1; n < 5; n++)
	
	{	if(record[n]>0)
		printf("+%d",record[n]);
		else if(record[n]<0)
    	printf("%d",record[n]);

	}
	printf("=%d\n",result);
}