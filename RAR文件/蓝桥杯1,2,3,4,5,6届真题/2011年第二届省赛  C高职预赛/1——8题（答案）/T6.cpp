
/*
�ο��𰸣�
��1�� h(space+1, x-1)   (6��)
��2�� x-i              ��3�֣�

(char)((int)x-i) ��ȻҲ�ǿ��Ե�
�粻��ȷ������Ҫ�����������ʵ��
*/

#include "stdafx.h"

void h(int space, char x)
{
	int i;
	if(x<'A' || x>'Z') return;
	h(space+1, x-1);  // ���1
	for(i=0; i<space; i++) printf(" ");
	for(i=0; i<x-'A'; i++) printf("%c",'A'+i);
	for(i=0; i<=x-'A'; i++) printf("%c",x-i);  //���2
	printf("\n");
}

int main(int argc, char* argv[])
{
	
	h(6,'E');
	return 0;
}

