/*
����
���ڸ���һ����Сд��ĸ����ַ�����Ҫ���ҳ��ַ����г��ִ���������ĸ��������ִ��������ĸ�ж����ô�����С���Ǹ���
����
��һ������һ��������T��0<T<25��
���T������һ���ַ���s,s����С��1010��
���
ÿ���������ռһ�У�������ִ��������ַ���
��������
3
abcd
bbaa
jsdhfjkshdfjksahdfjkhsajkf
�������
a
a
j
*/
#include <stdio.h>
#include <string.h>

main()
{
	int T;
	
	scanf("%d",&T);
	while(T--)
	{
		char str[1015];
		int Letter_num[26]={0};
		int i,max=0,temp;
		
		scanf("%s",str);
		for(i=0;i<strlen(str);i++)
		{
			Letter_num[str[i]-97]++;
		}
		for(i=0;i<26;i++)
		{
			if(Letter_num[i]>max)
			{
				max=Letter_num[i];
				temp=i;
			}
		}
		printf("%c\n",97+temp);
	}
	
	return 0;
}
