/*

蚂蚁问题 

一根27厘米的细木杆，在第3厘米、7厘米、11厘米、17厘米、23厘米这五个位置上各有一只蚂蚁。
木杆很细，只能同时通过一只蚂蚁。
开始时，蚂蚁的头朝左还是朝右是任意的，它们只会朝前走或调头，但不会后退。
当任意两只蚂蚁碰头时，两只蚂蚁会同时调头朝反方向走。假设蚂蚁们每秒钟可以走一厘米的距离。
    
编写程序，求所有蚂蚁都离开木杆的最小时间和最大时间。

穷举所有开始状态，向左走为0，向右走为1（略） 

（最优解） 

我们可以这么想，在相遇时,两只蚂蚁可以穿过对方的身体，只不过是交换了身份而已，即把A看作B，B看作A，即他们仍朝各自的方向行走，而互不受影响。
所以说.
最大时间当然就是要跑最长距离才能出去的那只蚂蚁所花的时间 27-3=24

*/
#include<stdio.h>

int get_time(int a, int b, int c, int d, int e)
{
	int n=5;
	int t=0;
	int j1=3,j2=7,j3=11,j4=17,j5=23;
	int st1=1,st2=1,st3=1,st4=1,st5=1;
	
	while(n>0)
	{	
//		检测是否死循环
//		printf("d");
		
		//消除判断及移动方向判断
		if(j1>0||j1<27)
		if(a==0)
		j1--;
		else
		j1++;
		
		if(j2>0||j2<27)
		if(b==0)
		j2--;
		else
		j2++;
		
		if(j3>0||j3<27)
		if(c==0)
		j3--;
		else
		j3++;
		
		if(j4>0||j4<27)
		if(d==0)
		j4--;
		else
		j4++;
		
		if(j5>0||j5<27)
		if(e==0)
		j5--;
		else
		j5++;
		
		//相遇则换方向 
		if(j1==j2&&j1>0&&j1<27)
		{
			a=!a;
			b=!b;
		}
		if(j2==j3&&j2>0&&j2<27)
		{
			b=!b;
			c=!c;
		}
		if(j3==j4&&j3>0&&j3<27)
		{
			c=!c;
			d=!d;
		}
		if(j4==j5&&j4>0&&j4<27)
		{
			d=!d;
			e=!e;
		}
		
		t++;
		//离开蚂蚁判定 
		if(st1)
		if(j1==0||j1==27)
		{
			n--;
			st1=0;
		}
		if(st2)
		if(j2==0||j2==27)
		{
			n--;
			st2=0;
		}
		if(st3)
		if(j3==0||j3==27)
		{
			n--;
			st3=0;
		}
		if(st4)
		if(j4==0||j4==27)
		{
			n--;
			st4=0;
		}
		if(st5)
		if(j5==0||j5==27)
		{
			n--;
			st5=0;
		}
//		printf("%d\n",n);
	}
	
	return t;
}

main()
{
	int a,b,c,d,e;
	int max=0;
	int min=20;
	int time;
	 
	//枚举所有初始状态，0左，1右 
	for(a=0;a<2;a++)
	for(b=0;b<2;b++)
	for(c=0;c<2;c++)
	for(d=0;d<2;d++)
	for(e=0;e<2;e++)
	{
		time=get_time(a,b,c,d,e);
		if(max<time)
		max=time;
		if(min>time)
		min=time;
	}
	printf("最大时间为：%d\n最小时间为：%d\n",max,min);
	
	return 0;
}
