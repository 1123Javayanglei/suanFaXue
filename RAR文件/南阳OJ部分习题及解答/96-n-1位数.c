/*
����
��֪w��һ������10��������1000000���޷�����������w��n(n��2)λ�������������w�ĺ�n-1λ������

����
��һ��ΪM����ʾ��������������
������M�У�ÿ�а���һ���������ݡ�
���
���M�У�ÿ��Ϊ��Ӧ�е�n-1λ��������ǰ׺0��������������λ�⣬����λ��Ϊ0�������0��
��������
4
1023
5923
923
1000
�������
23
923
23
0
*/
#include <stdio.h>

void num(unsigned int w,int *t,int *s)
{
	int i;
	//���� 
	if(w<10)
	return ;
	//�ݹ�
	i=w%10;
	w/=10;
	num(w,t,s);
	if(i!=0&&*t==0)
	*t=1;
	//���
	if(*t==1)
	{
		printf("%d",i);
		*s=1;
	}
	else if(*t==0&&i!=0)
	{
		printf("%d",i);
		*s=1;
	}
	else
	;
}
main()
{
	int M;
	
	scanf("%d",&M);
	while(M--)
	{
		unsigned int w;
		int t=0,s=0;
		
		scanf("%d",&w);
		num(w,&t,&s);
		if(s==0)
		printf("0");
		printf("\n");
	}
	
	return 0;
} 
