/*
����
��С�ܵĴʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ�����������֤���������ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ��� 
���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ��������maxn-minn��һ����������ô��С�ܾ���Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡�

����
��һ������N(0<N<100)��ʾ��������������
ÿ�������������ֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��
���
ÿ�����������������У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky Word�������������No Answer���� 
�ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0
��������
2
error
olympic
�������
Lucky Word
2
No Answer
0
*/
#include <stdio.h>
#include <string.h>

int permit(int num)
{
	int i;
	if(num<=1)
	return 0;
	for(i=2;i*i<num+1;i++)
	{
		if(num%i==0)
		return 0;
	}
	return 1;
}

main()
{
	int N;
	
	scanf("%d",&N);
	
	while(N--)
	{
		char str[100];
		int num[100]={0},maxn,minn;
		int i=1,j=0,k=1;
		num[0]=1;
		
		scanf("%s",str);
		//���������ĸ��������ĸ�ĸ����ֱ����maxn��minn 
		while(i<strlen(str))
		{
			int st=0;
			int sl;//9999
			for(j=0;j<k;j++)
			{
				if(str[i]==str[j])
				{
					num[j]++;
					st=1;
					break;
				}
			}
			if(st==0)
				{
					str[k]=str[i];
					num[k]=1;
					k++;
				}
			i++;
		}
		minn=maxn=num[0];
		for(i=0;i<k;i++)
		{
			if(num[i]>maxn)
			maxn=num[i];
			if(num[i]<minn)
			minn=num[i];
		}
		
		if(permit(maxn-minn))
		{
			printf("Lucky Word\n%d\n",maxn-minn);
		}
		else
		{
			printf("No Answer\n0\n");
		}
	}
	
	return 0;
}
/*
		for(i=0;i<k;i++)
		{
			printf("%c\n",str[i]);
			printf("%d\n",num[i]);
		}
*/
