
/*
�ο��𰸣�i+=a
���� i = i + a;

ע�⣺i++
��Ȼ���Եõ���ȷ��������������⣨��Ч���У��������֡�

*/

#include "stdafx.h"

int f(int a, int b)
{
	int i;
	for(i=a;;i+=a)  // ���
	{
		if(i%b==0) return i;
	}
}

int main(int argc, char* argv[])
{
	printf("%d\n", f(12,15));
	return 0;
}

