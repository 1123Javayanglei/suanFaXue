//���һ����


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
	//�����nС�����ĺ�
	while(--k >= 0)
	{   
		sum += s[k];
	}
	//����sum�յ���n�������,���ж�
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
	//����sumС��n��ȡ�մ���n�ĵ�һ��ֵ
	if(sum < n)
	{
		if(a == 1)
			record[count++] = s[i]; 
		else 
			record[count++] = -s[i];
		n = s[i] - n; 
		//********************************�仯a��ֵ��ȷ������
		a *= -1;				//�л�������
		fun(s, n, count, a);
	}
	//����sum����n��ȡ��С��n�ĵ�һ��ֵ
	else if(sum > n)
	{
		if(a == 1)
			record[count++] = s[i-1]; 
		else 
			record[count++] = -s[i-1];
		n = n - s[i-1];
		//***************************************�仯a��ֵ��ȷ������
		a *= 1;                  //�л�������
		fun(s, n, count, a);
	}

	
}













main()
{
	int s[5] = {1, 3, 9, 27, 81};
	int n,result;
	int aa = 1;            //��ʾ���ִ洢����1Ĭ����  1 +�� -1 -
	int *p = record;
	counts = 0;
	printf("������һ��1��121֮�����:");
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