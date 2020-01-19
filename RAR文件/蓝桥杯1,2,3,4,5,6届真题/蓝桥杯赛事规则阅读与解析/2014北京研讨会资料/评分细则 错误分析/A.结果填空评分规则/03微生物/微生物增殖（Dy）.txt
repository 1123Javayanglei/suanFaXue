/*

    假设有两种微生物 X 和 Y

    X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。

    一个新出生的X，半分钟之后吃掉1个Y，并且，从此开始，每隔1分钟吃1个Y。

    现在已知有新出生的 X=10, Y=89，求60分钟后Y的数目。

    如果X=10，Y=90  呢？

    本题的要求就是写出这两种初始条件下，60分钟后Y的数目。


    题目的结果令你震惊吗？这不是简单的数字游戏！真实的生物圈有着同样脆弱的性质！也许因为你消灭的那只 Y 就是最终导致 Y 种群灭绝的最后一根稻草！
    

    请忍住悲伤，把答案写在“解答.txt”中，不要写在这里！
*/
#include<stdio.h>
int num(int x,int y)
{
	int i;
	int x1,x2=0;
	x1=x;
	printf("时间\t\t新生\t老生\tY的数目\n"); 
	for(i=1;i<=120;i++)
	{
		printf("第%3d分钟",i/2);
		if(i%2!=0)
		printf("半");
		printf("\t");
		y=y-x1;	
		if(i!=1)
		if((i+1)%2==0)
		y=y-x2;
		x2+=x1;
		x1=0;
		if(y<=0)
		{
			y=0;
			break;
		}
		if(i%4==0)
		y*=2;
		if(i%6==0)
		{
			x2*=2;
			x1=x2/=2;
		}
		printf("%d\t%d\t%d\n",x1,x2,y);
	}
	return y;
}
main()
{
	int x,y;
	int num_y;
	scanf("%d%d",&x,&y);
	num_y=num(x,y);
//	num_y=num(10,90);
	printf("\n60分钟后Y的数目为：%d\n",num_y);
	return 0;
} 