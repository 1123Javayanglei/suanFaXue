#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	char str1[100];

	char *p;
	int n=0;//字符串的长度
	int m=0;
	int i;

	p=str;
    printf("请输入一个字符串:");
	gets(str);

	n=sizeof(str);
	while(*p!='\0')
	{
		if(*p>='a' && *p<='z')
		{
			*p=*p-32;
			p++;
		}
		while(*p!=' ')
			p++;
		p++;
	}

 
	for(i=0;i<n;i++)
	{
		
		str1[m]=str[i];
		if(str[i]>='a'&&str[i]<='z'&&str[i+1]>='0'&&str[i+1]<='9')
		{
			m=m+1;
			str1[m]='_';
		}
		if(str[i]>='A'&&str[i]<='Z'&&str[i+1]>='0'&&str[i+1]<='9')
		{
			m=m+1;
			str1[m]='_';
		}
		if(str[i]>='0'&&str[i]<='9'&&str[i+1]>='a'&&str[i+1]<='z')
		{
			
			
			m=m+1;
			str1[m]='_';
		}
		if(str[i]>='0'&&str[i]<='9'&&str[i+1]>='A'&&str[i+1]<='Z')
		{
			
			
			m=m+1;
			str1[m]='_';
		}
		while(str[i]==' '&& str[i+1]==' ')
		{
               i++;
		
		}
		
		
		m++;	
	}
    printf("%s",str1);
}