/*
����
�����ϲ���о����ƺ��룬�ӳ��ƺ����Ͽ��Կ�������ע����������о����֣����ƺ����ǰ��ֵ��򷢷ŵģ��������ռ��˺ܶ೵�ƺ��룬������Ƴ�������ж�ע�����ĺ��롣���ƺ�����5����ĸ���������
����
��һ����n��������n�����ݣ��ڶ�����m������m����m�����ƺ���
����n<100,m<1000
���
���ע�����ĳ��ƺ�
��������
1
4
AA100
aa100
0o2r4
ye2er
�������
0o2r4
*/
#include <stdio.h>
#include <string.h>

main()
{
	int n;

	scanf("%d",&n);
	while(n--)
	{
		int m,i=1;
		char temp[6],str[6];
		
		scanf("%d",&m);
		while(m--)
		{
			if(i)
			{
				scanf("%s",temp);
				strcpy(str,temp);
				i--;
			}
			else
			{
				scanf("%s",str);
				if(strcmp(temp,str)>0)
				strcpy(temp,str);
			}		
		}
		printf("%s\n",temp);
	}
	
	return 0;
} 
