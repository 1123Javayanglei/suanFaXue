/*
����
1��2��3�� ��n��n(0<n<=1000000000)�������ж��ٸ������Ա�������b������
����
���������������
ÿ������ռһ�У�ÿ�и�������������n��b��
���
���ÿ��������Ӧ�Ľ����
��������
2 1
5 3
10 4
�������
2
1
2
*/
//�ⷨһ 
#include <stdio.h>

main()
{
	long long n,b;
	
	while(scanf("%lld%lld",&n,&b)!=EOF)
	{
		printf("%lld\n",n/b);
	}
	
	return 0;
}
//�ⷨ������ʱ 
/*
#include <stdio.h>

main()
{
	long long n,b;
	
	while(scanf("%lld%lld",&n,&b)!=EOF)
	{
		long long sum=0,i;
		
		for(i=b;i<=n;i+=b)
		{
			sum++;
		}
		
		printf("%lld\n",sum);
	}
	
	return 0;
}
*/
