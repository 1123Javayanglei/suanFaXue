/*
����
����A+B Problem֮��Yougth�о�̫���ˣ������������������������ת����ӵ�ֵ���������
����
�ж���������ݡ�ÿ�����������m��n�����ݱ�֤int��Χ����m��nͬʱΪ0�Ǳ�ʾ���������
���
�����ת����ӵĽ����
��������
1234 1234
125 117
0 0
�������
8642
1232
*/
//�ⷨһ��
#include <stdio.h>

int NumberFormat(int n)
{
	int sum=0;
	while(n)
	{
		sum=sum*10+n%10;
		n/=10;
	}
	return sum;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&(a||b))
	{
		printf("%d\n",NumberFormat(a)+NumberFormat(b));
	}
	return 0;
}
//�ⷨ�����ݹ�