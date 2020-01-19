
#include <stdio.h>

int main()
{
	// 先读入一个整数，再读入2个串 
	int a;
	char b1[100];
	char b2[100];
	
	scanf("%d", &a);
	fgets(b1, sizeof(b1), stdin);
	fgets(b2, sizeof(b2), stdin);
	
	printf("a = %d\n", a);
	printf("b1 = %s\n", b1);
	printf("b2 = %s\n", b2);
		
	return 0;
}
