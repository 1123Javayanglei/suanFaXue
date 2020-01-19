
#include <stdio.h>

int main()
{
	long long a = 1234567890123456789;
	printf("%I64d\n", a*2);
	
	long long b = 0;
	printf("%I64u\n", b-1);
	
	return 0;
}
