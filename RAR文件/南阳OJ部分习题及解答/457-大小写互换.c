/*
����
      ���ڸ�����һ��ֻ������Сд��ĸ���ַ����������ո�ͻ��У�Ҫ������еĴ�д����Сд��Сд���ɴ�д��Ȼ�������������ַ�����
����
��һ��ֻ��һ������m��m<=10),��ʾ��������������
��������m�У�ÿ����һ���ַ��������Ȳ�����100����
���
�����������ַ�����ÿ�����ռһ�С�
��������
2
Acm
ACCEPTED
�������
aCM
accepted
*/
#include <stdio.h>
#include <string.h>

main()
{
	int m;
	
	scanf("%d",&m);
	while(m--)
	{
		char str[100];
		int i;
		
		scanf("%s",str);
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			printf("%c",str[i]-32);
			else
			printf("%c",str[i]+32);
		}
		printf("\n");
	} 
		
	return 0;
}
