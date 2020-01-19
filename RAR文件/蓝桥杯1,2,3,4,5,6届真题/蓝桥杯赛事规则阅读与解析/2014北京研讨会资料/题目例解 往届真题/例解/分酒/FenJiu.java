
/*
  酒杯容量 9 7 4 2
  开始状态 9 0 0 0
  目标状态 3 3 3 0
  
  求最小步数
*/

import java.util.*;

public class FenJiu
{
	static int[] v0 = {9,7,4,2};
	static Map map = new HashMap();
	
	static int[] arrayCopy(int[] s)
	{
		int[] s1 = new int[s.length];
		for(int i=0; i<s.length; i++) s1[i] = s[i];
		return s1;
	}

	static String arrayToString(int[] s)
	{
		String t = "";
		for(int i=0; i<s.length; i++)
			t = t + s[i] + ",";
		
		return t;		
	}
	
	static int[] stringToArray(String s)
	{
		String[] t = s.split(",");
		int[] x = new int[t.length];
		for(int i=0; i<x.length; i++) x[i] = Integer.parseInt(t[i]);
		return x;
	}

	
	// 从x倒入y
	static int[]  move(int[] s, int x, int y)
	{
		if(s[x]==0) return null;
		if(s[y]==v0[y]) return null;
		
		int[] s1 = arrayCopy(s);
		
		int d = v0[y]-s[y]; // 目标瓶子差多少？
		
		if(s[x] > d){
			s1[y] = v0[y];
			s1[x] -= d;
		} 
		else{
			s1[y] += s[x];
			s1[x] = 0;
		}
		return s1;
	}
	
	// 检测历史记录
	static int his(int[] s)
	{
		Integer x = (Integer)map.get(arrayToString(s));
		if(x==null) return -1;
		
		return x;
	}
	
	public static void f()
	{
		for(;;){
			Map map1 = new HashMap();
			
			for(Object x: map.keySet()){
				int[] x1 = stringToArray((String)x);
				for(int i=0; i<x1.length; i++)
				for(int j=0; j<x1.length; j++)
				{
					if(i==j) continue;
					int[] x2 = move(x1,i,j);
					if(x2==null) continue;
					
					int n = (Integer)map.get(x) + 1;
					Integer old = (Integer)map.get(arrayToString(x2));
					if(old==null)
						map1.put(arrayToString(x2),n);
					else if(n<old)
						map.put(arrayToString(x2),n);
				}
			}
			
			if(map1.size()==0) break;
			map.putAll(map1);
		}
	}
	
	public static void main(String[] args)
	{
		int[] s0 = {9,0,0,0};
		int[] d0 = {3,3,3,0};
		map.put(arrayToString(s0),0);
		
		f();  // 生成尽可能多的状态，及其最小步数
		
		
		for(Object x: map.keySet()){
			
			System.out.println(x + "   " + map.get(x));
		}
		
		
		System.out.println("答案：" +  map.get(arrayToString(d0)));
	}
}