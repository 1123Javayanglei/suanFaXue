/*
����
��nյ�ƣ����Ϊ1~n����1���˰����еƴ򿪣���2���˰������б��Ϊ2 �ı����Ŀ��أ���Щ�ƽ����ص�������3 ���˰������б��Ϊ3�ı����Ŀ��أ����йص��ĵƽ����򿪣����ŵĵƽ����رգ����������ơ�һ����k���ˣ����������Щ�ƿ��ţ����룺n��k��������ŵĵƱ�š�k��n��1000
����
����һ�����ݣ�n��k
���
������ŵĵƱ��
��������
7 3
�������
1 5 6 7
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

main()
{
	int *lamp,n,k;
	int i,j;
	
	scanf("%d%d",&n,&k);
	//��̬����n+1��int�͵��ڴ�ռ� 
	lamp=(int *)malloc((n+1)*sizeof(int));
	//�Ը��ڴ�ռ�����
	memset(lamp,0,n+1);
	for(i=1;i<k+1;i++)
	for(j=1;j<n+1;j++)
	{
		if(j%i==0)
		{
			lamp[j]=!lamp[j];
		}
	}
	for(i=1;i<n+1;i++)
	{
		if(lamp[i]==1)
		{
			printf("%d ",i);
		}
	}
	free(lamp);
	printf("\n");
	
	return 0;
}
