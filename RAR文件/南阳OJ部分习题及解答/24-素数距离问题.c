/*
���� ���ڸ�����һЩ����Ҫ����д��һ�����������Щ����������������������������೤�ȡ���������еȾ��볤�����������������ֵ����Ӧ���롣
 �����������������������������������������������0
�����һ�и���������������N(0<N<=10000)
��������N��ÿ����һ������M(0<M<1000000)�����ÿ������������� A B.
����A��ʾ����Ӧ�������������������B��ʾ���ľ��롣��������3
6
8
10
�������5 1
7 1
11 1
*/

#include <stdio.h>

int is_permit(int num)
{
	int i;
	if(num>1)
	{
		for(i=2;i*i<num+1;i++)
		{
			if(num%i==0)
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

main()
{
	int n,m;
	int i;
	
	scanf("%d",&n);
	//n��������� 
	while(n--)
	{
		scanf("%d",&m);
		
		if(is_permit(m))
		{
			printf("%d 0\n",m);
		}
		else
		{
			for(i=1;;i++)
			{
				if(is_permit(m-i))
				{
					printf("%d %d\n",m-i,i);
					break;
				}
				if(is_permit(m+i))
				{
					printf("%d %d\n",m+i,i);
					break;
				}
			}
		}
	}
	
	return 0;
}
