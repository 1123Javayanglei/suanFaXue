/*
����
��дһ������ʵ�ֽ��ַ����е�����"you"�滻��"we"
����
��������������� 

ÿ��������һ���ַ��������Ȳ�����1000 
������EOF����
���
���������ÿһ�У�����滻����ַ���
��������
you are what you do
�������
we are what we do
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

main()
{
	char *p,c;
		
	while((c=getchar())!=EOF)
	{
		int i=0,j;
		
		p=(char *)malloc(1000*sizeof(char));
		p[0]=c;
		while(p[i]!='\n')
		{
			i++;
			p[i]=getchar();
		}

		for(j=0;p[j]!='\n';j++)
		{
			if(p[j]=='y'&&p[j+1]=='o'&&p[j+2]=='u')
			{
				printf("we");
				j=j+2;
			}
			else
			{
				printf("%c",p[j]);
			}
		}
		printf("\n");
		
		free(p);
	}
	
	return 0;
}
