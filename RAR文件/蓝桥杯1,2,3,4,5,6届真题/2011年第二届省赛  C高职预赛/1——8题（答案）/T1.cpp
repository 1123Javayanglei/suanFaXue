
/*
�ο��𰸣�money * 1.03

Ҳ�������߼��ȼۣ�
money + money * 3 / 100;

*/

#include "stdafx.h"

int main(int argc, char* argv[])
{
	double money = 1000;
	int n = 5;
	int i;
	for(i=0; i<n; i++)
	{
		money = money * 1.03;  // ���
		money -= 100; 
	}
	printf("%.2f\n", money);

	return 0;
}

