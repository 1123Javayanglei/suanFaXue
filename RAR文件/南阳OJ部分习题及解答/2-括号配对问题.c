/*
����
���ڣ���һ���������У����������������Ƿ���ԡ�
����
��һ������һ����N��0<N<=100��,��ʾ��N��������ݡ������N����������������ݣ�ÿ���������ݶ���һ���ַ���S(S�ĳ���С��10000����S���ǿմ�����
����������������5�顣���ݱ�֤S��ֻ����"[","]","(",")"�����ַ�
���
ÿ���������ݵ����ռһ�У�������ַ�������������������Եģ������Yes,�������������No
��������
3
[(])
(])
([[]()])
�������
No
No
Yes
Yes
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
	
main()
{

	int i,n;
	int st=0,sp=0;
	int num[100]={0};

	scanf("%d",&n);
	
	loop:
	while(n--)
	{
		char* str = (char *)malloc(10005);
		//��ʼ����������
		st=0;
		sp=0; 
		
		scanf("%s",str);		
		//�ַ�������Ϊ�����϶����ܶԳ� 
		if(strlen(str)%2!=0)
		{
			printf("No\n");
			continue;
		}
		
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='(')
			st+=1;
			if(str[i]==')')
			st-=1;
			if(str[i]=='[')
			sp+=1;
			if(str[i]==']')
			sp-=1;
		
//			printf("%d %d\n",st,sp);
			
			if(sp<0||st<0||(str[i]=='('&&str[i+1]==']')||(str[i]=='['&&str[i+1]==')'))
			{
				printf("No\n");
				goto loop;
			}
		}
		printf("Yes\n");
		
		free(str);
	}
	
	return 0;
}

