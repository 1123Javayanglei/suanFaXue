/*
����
���һ����5��������ȡ��С����������ĳ���
����
����ֻ��һ��������ݣ�Ϊ���������1���������
���
�������������һ��Ϊ��������е���Сֵ���ڶ���Ϊ��������е����ֵ�����������Կո�񿪡�
��������
1 2 3 4 5
�������
1 5
*/

#include <stdio.h>

main()
{
	int min,max;
	int i,temp;
	
	scanf("%d",&min);
	max=min;
	
	for(i=0;i<4;i++)
	{
		scanf("%d",&temp);
		if(temp<min)
		min=temp;
		if(temp>max)
		max=temp;
	}
	
	printf("%d %d",min,max);
	
	return 0;
}
