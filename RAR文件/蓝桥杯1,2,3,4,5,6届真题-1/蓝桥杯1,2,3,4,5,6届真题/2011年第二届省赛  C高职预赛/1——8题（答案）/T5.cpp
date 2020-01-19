
/*
 �ο��𰸣�
 ��1�� len+1     (2��)
 ��2�� 0         (5��)

 ��1��strlen(s) + 1  ��һ����
 ��2��'\0'  (char)0  NULL ��һ����  

 ����δ֪�Ķ������������һ��
*/



#include "stdafx.h"
#include "stdlib.h"
#include "string.h"

void shift(char* s, int n)
{
	char* p;
	char* q;
	int len = strlen(s);
	if(len==0) return;
	if(n<=0 || n>=len) return;

	char* s2 = (char*)malloc(len+1);  // ���1
	p = s;
	q = s2 + n % len;
	while(*p)
	{	
		*q++ = *p++;
		if(q-s2>=len)
		{
			*q = 0; // ���2
			q = s2;
		}
	}
	strcpy(s,s2);
	free(s2);
}

int main(int argc, char* argv[])
{
	char x[] = "abcdefg";
	shift(x,6);
	printf("%s\n", x);
	return 0;
}

