/*
����
�����������꣨X1,Y1��,��X2,Y2��(0<=x1,x2,y1,y2<=1000),���㲢��������ľ��롣
����
��һ������һ������n��0<n<=1000��,��ʾ��n���������;
���ÿ��ռһ�У���4��ʵ����ɣ��ֱ��ʾx1,y1,x2,y2,����֮���ÿո������
���
����ÿ���������ݣ����һ�У����������λС����
��������
2
0 0 0 1
0 1 1 0
�������
1.00
1.41
*/
#include <stdio.h>
#include <math.h>

float Distance(float x1,float x2,float y1,float y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

main()
{
	int n;
	
	scanf("%d",&n);
	while(n--)
	{
		float x1,y1,x2,y2;
		
		scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
		printf("%.2f\n",Distance(x1,x2,y1,y2));
	}
	
	return 0;
}
