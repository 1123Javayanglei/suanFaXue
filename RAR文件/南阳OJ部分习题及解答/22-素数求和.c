/*
����
���ڸ���N������0<N<1000��������Ҫ����д��һ�������ҳ���N�����е���������������͡�
����
��һ�и�������M(0<M<10)����������������
ÿ��������ݵ�һ�и���N���������������ݵ�������
��������N����ΪҪ���Ե����ݣ�ÿ����С��1000
���
ÿ��������ݽ��ռһ�У���������Ĳ������ݵ�����������
��������
3
5
1 2 3 4 5
8
11 12 13 14 15 16 17 18
10
21 22 23 24 25 26 27 28 29 30
�������
10
41
52
*/

#include <stdio.h>
#include <math.h>

int is_permit(int num)
{
	int i;
	
	if(num==1)
	return 0;
	
	for(i=2;i*i<num+1;i++)
	{
		if(num%i==0)
		return 0;
	}
	
	return 1;
}

main()
{
	int n,m;
	int i,temp;
	int num[1005]={0},sum[15]={0};
	
//	for(i=1;i<50;i++)
//	printf("%d=%d\n",i,is_permit(i)); 
	
	scanf("%d",&m);
	temp=m;
	
	//����temp������
	while(m--)
	{
		//n������ 
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			
			//n�������е������ʹ����Ӧ������ 
			if(is_permit(num[i]))
			{
				sum[temp-m-1]+=num[i];
			}
			
//			printf("��ǰ����������%d\n",sum[temp-m-1]);
		}
	}
	
	//�����temp������
	for(i=0;i<temp;i++)
	{
		printf("%d\n",sum[i]);
	} 
	
	return 0;
}







