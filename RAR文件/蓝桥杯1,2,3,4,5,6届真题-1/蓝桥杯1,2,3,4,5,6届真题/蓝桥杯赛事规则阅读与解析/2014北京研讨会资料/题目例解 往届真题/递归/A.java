
/*
  1. 寻找相似性，以便踢皮球
  2. 制造“出口”
  
  3. 没有相似性，增加参数试试
  
  4. 平地起风雷
  5. 更多灵感，更苛刻的训练： haskell cheatsheet
  
  6. 效率问题：做缓冲，防止重复计算
  
*/

public class A
{
	// 打印从 0 到 n
	static void f(int n)
	{
		if(n<0) return;
		//if(n>0) f(n-1);
		f(n-1);
		System.out.println(n);
	}


	// 打印从a到b
	static void g(int a, int b)
	{
		if(a>b) return;
		System.out.println(a);
		g(a+1,b);
	}
	
	// m个球中取n个，多少取法？
	static int h(int m, int n)
	{
		//System.out.println(m + "," + n);
		if(m<n) return 0;
		if(m==n) return 1;
		if(n==0) return 1;
		
		return h(m-1,n-1) + h(m-1,n);
	}
	
	public static void main(String[] args)
	{
		int n = h(5,3);
		System.out.println(n);

		
		
		//递归思想
		// 踢皮球  责任转嫁 ...
		
		//for(int i=0; i<10; i++) System.out.println(i);
		//改写循环
		//f(9);
		
		//g(0,9);
		
	}
}