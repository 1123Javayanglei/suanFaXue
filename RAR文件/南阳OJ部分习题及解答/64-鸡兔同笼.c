/*
����
��֪�����õ�������Ϊn,������Ϊm������n��m,������������õ���Ŀ������޽⣬�������No answer��(��Ҫ����)��
����
��һ������һ������a,������������м������ݣ��ڽ�������(a<10)
a���ÿ�ж���һ��n��m.(0<m,n<100)
���
������õĸ���������No answer
��������
2
14 32
10 16
�������
12 2
No answer
*/
#include <stdio.h>

main()
{
	int a;
	
	scanf("%d",&a);
	while(a--)
	{
		int m,n;
		int i,temp=0;
		
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			if(i*4+(n-i)*2==m)
			{
				printf("%d %d\n",n-i,i);
				temp=1;
			}
		}
		if(temp==0)
		printf("No answer\n");
	}
	
	return 0;
}
