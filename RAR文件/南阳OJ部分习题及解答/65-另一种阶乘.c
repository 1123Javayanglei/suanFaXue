#include <stdio.h>

main()
{
	int a,n;
	int i,j;
	int	product=1,sum=0;
	
	scanf("%d",&a);
	
	while(a--)
	{
		scanf("%d",&n);
		
		//����1��n�ĺ� 
		for(i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				//ż��ʱ������˻� 
				for(j=1;j<i;j+=2)
				{
					product*=j;
				}
			}
			else
			{
				//����ʱ������˻�
				for(j=1;j<=i;j+=2)
				{
					product*=j;
				}
			}
			sum+=product;
			
			product=1; 
		}
		
		//����ͣ������³�ʼ������ 
		printf("%d\n",sum);
		sum=0;
	}
	
	return 0;
}
