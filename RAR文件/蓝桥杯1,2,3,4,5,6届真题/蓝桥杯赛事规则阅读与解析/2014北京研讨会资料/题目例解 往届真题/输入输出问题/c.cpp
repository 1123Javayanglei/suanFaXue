
#include <stdio.h>
#include <string.h>

int main()
{
	// 先读入一个整数，再读入2个串 
	int a;
	char b1[100];
	char b2[100];
	
	scanf("%d\n", &a);
	fgets(b1, sizeof(b1), stdin);
	fgets(b2, sizeof(b2), stdin);
	
	//b1[strlen(b1)-1] = '\0';  xxxxxxx
	//if(.... == '\n') ..... 
	
	printf("a = %d\n", a);
	printf("b1 = %s\n", b1);  //串中含有\n，可能需要去掉 
	printf("b2 = %s\n", b2);
		
	return 0;
}
