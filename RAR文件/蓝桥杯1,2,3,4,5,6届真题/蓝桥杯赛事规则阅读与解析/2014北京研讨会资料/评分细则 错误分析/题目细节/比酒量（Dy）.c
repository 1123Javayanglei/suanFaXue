/*
	有一群海盗（不多于20人），在船上比拼酒量。过程如下：打开一瓶酒，所有在场的人平分喝下，有几个人倒下了。再打开一瓶酒平分，又有倒下的，再次重复...... 
	
	直到开了第4瓶酒，坐着的已经所剩无几，海盗船长也在其中。当第4瓶酒平分喝下后，大家都倒下了。

    等船长醒来，发现海盗船搁浅了。他在航海日志中写到：“......昨天，我正好喝了一瓶.......奉劝大家，开船不喝酒，喝酒别开船......”

    请你根据这些信息，推断开始有多少人，每一轮喝下来还剩多少人。

    如果有多个可能的答案，请列出所有答案，每个答案占一行。

    格式是：人数,人数,...

    例如,有一种可能是：20,5,4,2,0

*/
#include<stdio.h>
#include<math.h>
main()
{
	int i,j,m,n;
	for(i=20;i>=4;i--)
	for(j=19;j>=3;j--)
	for(m=18;m>=2;m--)
	for(n=17;n>=1;n--)
	{
		if(i>j&&j>m&&m>n)
		{
			if(1.0/i+1.0/j+1.0/m+1.0/n==1)
			{
//				printf("%f %f %f %f\n",1.0/i,1.0/j,1.0/m,1.0/n);//数据验证 
				printf("%d,%d,%d,%d,%d\n",i,j,m,n,0);
			}
		}
	}
} 
