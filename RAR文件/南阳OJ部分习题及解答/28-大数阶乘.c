/*
����
���Ƕ�֪����μ���һ�����Ľ׳ˣ����ǣ����������ܴ��أ����Ǹ����ȥ���������������
����
����һ������m(0<m<=5000)
���
���m�Ľ׳ˣ������������֮������һ�����з�
��������
50
�������
30414093201713378043612608166064768844377641568960512000000000000

�ⷨ��
*ע�� ����5000����16325λ������������뿪�Ĵ�Щ

������Ժ���
void printA(int P[])
{
	int i;
	for(i=0;i<MaxSize;i++)
	{
		printf("%d",P[i]);
	}
	printf("\n");
	
	return ;
} 
*/
#include <stdio.h>
#include <string.h>
#define MaxSize 17000

void resultProduct(int P[],int num)
{
	int i,tp=0,st=0;
	
	for(i=0;i<MaxSize;i++)
	{
		st=tp;
		tp=(P[i]*num+st)/10;
		P[i]=(P[i]*num+st)%10;
	}

	return ;
}

void printArray(int P[])
{
	int i=MaxSize-1;
	
	while(!P[i])
	{
		i--;
	}
	
	while(i>=0)
	{
		printf("%d",P[i]);
		i--;
	}
	
	printf("\n");
	
	return ;
}

main()
{
	int A[MaxSize],n;
	int i;
	
	//���������Ҹ�λ��ʼ��Ϊ1 
	memset(A,0,MaxSize*sizeof(int)); 
	A[0]=1;

	scanf("%d",&n);
	//��i���γ�������A 
	for(i=2;i<=n;i++)
	{
		resultProduct(A,i);
	}
	
	printArray(A);
	printf("\n");
	return 0;
}

