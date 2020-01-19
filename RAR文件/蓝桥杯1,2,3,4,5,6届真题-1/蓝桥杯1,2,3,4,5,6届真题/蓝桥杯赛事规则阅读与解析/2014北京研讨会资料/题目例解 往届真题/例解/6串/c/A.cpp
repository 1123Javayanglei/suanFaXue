
// c并没有数组，数组的本质也是个整数（内存地址） 
// 所谓c的串本质就是个整数 （内存地址） 
// 理解栈 

#include <stdio.h>

int main()
{
	char const * a = "abcd";
	char const * a2 = "abcd";
	
	char b[] = "abcd";
	char c[] = "xyz";
	//b[-1] = '*';
	*(b-1) = '*';
	
	printf("%s\n", c);
	
	/*
	printf("%d\n", a);
	printf("%d\n", a2);
	printf("%d\n", b);
	printf("%d\n", c);
	*/
	
	return 0;
}
