/*

思路：分两步
1.求分组		（分组求法  if(n%8==0) 组数=n/8 ;  if(n%8！=0)  组数=n/8+1 ;）
2.分组人数	（分组人数  while(单独的一组<=8)）

*/

#include<stdio.h>
#include<math.h>

main()
{
	int n;
	int i;
	int st,sp;
	int a,b;
	
	scanf("%d",&n);
	
	if(n<8)
	printf("%d\n",n);
	else if(n%8==0)
	{
		if(n==0)
		printf("0\n");
		for(i=0;i<n/8;i++)
		printf("8\n");
	} 
	else
	{
		//将余数给a，8给b 
		st=1;
		a=n%8;
		b=8;
		sp=8-a;
		
		while(n%8+n/8*st<8)
		{
			a+=n/8;
			b--;
			if(abs(a-b)>=sp)
			{
				a-=n/8;
				b++;
				break;
			}
			else
			sp=abs(a-b);
			st++;
			printf(" %d %d %d\n",a,b,st,sp);
		}
		
		if(a>b)
		printf("%d\n",a);
		
		for(i=0;i<n/8;i++)
		printf("%d\n",b);
		
		if(a<b)
		printf("%d\n",a);
	}
	
	return 0;
}