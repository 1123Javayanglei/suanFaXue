/*
����
���������ַ��������ظ����󣬰����ַ���ASCII���С�����˳������������ַ���
����
��һ������һ����N,��ʾ��N��������ݡ������N������������ݣ�ÿ���������ݶ���ռһ�У��������ַ���ɣ�֮���޿ո�
���
����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���
��������
3
qwe
asd
zxc
�������
e q w
a d s
c x z
*/
 
#include "stdio.h"

main()

{
	
char a,b,c,d;
	
int i;
	
scanf("%d",&i);
	
getchar();
	
while(i--)
	
{
		
scanf("%c%c%c",&a,&b,&c);
		
getchar();
		
if (a>b) {d=a;a=b;b=d;}
		
if (a>c) {d=a;a=c;c=d;}
		
if (b>c) {d=b;b=c;c=d;}
		
printf("%c %c %c\n",a,b,c);	
		
	
	
}


}
        