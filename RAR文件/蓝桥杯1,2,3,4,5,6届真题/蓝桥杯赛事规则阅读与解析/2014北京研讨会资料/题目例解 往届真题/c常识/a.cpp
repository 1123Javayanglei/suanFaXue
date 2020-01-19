
#include <stdio.h>
#include <math.h> 

int main()
{
	// 取得 pi 的精确值
	
	double pi = atan(1.0) * 4;
	
	printf("%f\n", pi);
	printf("%lf\n", pi);
	printf("%.20f\n", pi);
		
	return 0;
}
