
/*
  Interpreter 模式用于词法分析
  
  对巴克斯范式进行分析
*/


import java.util.*;

class Context
{
	public String data;
	public int p;
	public Map result = new HashMap();
}


interface EP
{
	boolean parse(Context context);
}

// 虚符号：表示句子终止
class Tend implements EP
{
	public boolean parse(Context context)
	{
		return context.p >= context.data.length();
	}	
}

// 虚终结符：表示不需要任何匹配
class Tnull implements EP
{
	public boolean parse(Context context)
	{
		return true;
	}	
}

// 终结符：实在的字母或运算符号
class T implements EP
{
	private char _c;
	
	public T(char x)
	{
		_c = x;
	}
	
	public boolean parse(Context context)
	{
		if(context.p >= context.data.length()) return false;
		
		if(context.data.charAt(context.p) != _c) return false; 

		context.p++;
		return true;	
	}
}

// 非终结符（内含元素的"或者"组合）
class NTor implements EP
{
	private String _name;
	private List _lst = new ArrayList();
	
	public NTor(String name)
	{
		_name = name;
	}
	
	public void add(EP ep)
	{
		_lst.add(ep);
	}

	
	public boolean parse(Context context)
	{
		for(int i=0; i<_lst.size(); i++){
			int old = context.p;
			EP ep = (EP)_lst.get(i);
			if(ep.parse(context)){ 
				// 如果是重要词汇，输出此词汇
				if(_name.equals("函数")){
					String s = "函数：" + context.data.substring(old, context.p);
					System.out.println(s);
				}
				return true;
			}
			else
				context.p = old;
		}
		return false;
	}
}

// 非终结符（内含元素的顺序组合）
class NTseq implements EP
{
	private List _lst = new ArrayList();
	private String _name;
	
	public NTseq(String name)
	{
		_name = name;
	}
	
	public void add(EP ep)
	{
		_lst.add(ep);
	}
	
	public boolean parse(Context context)
	{
		int old = context.p;
		for(int i=0; i<_lst.size(); i++){
			EP ep = (EP)_lst.get(i);
			if(!ep.parse(context)){
				context.p = old;
				return false;
			} 
		}
		
		// -------- 测试 
		// 如果是重要词汇，输出此词汇
		if(_name.equals("函数")){
			String s = "函数：" + context.data.substring(old, context.p);
			System.out.println(s);
		}
		// -------- 测试end

		return true;
	}
}

// 非终结符(某个表达式的1次或多次重复)
class NTrep implements EP
{
	private NTseq _me;  // 尽量使用组合，而不是继承
	
	public NTrep(String name, EP ep)
	{
		_me = new NTseq(name);
		_me.add(ep);
		
		NTor t = new NTor("");
		t.add(_me);
		t.add(new Tnull());
		_me.add(t);
	}
	
	public boolean parse(Context context)
	{
		return _me.parse(context);
	}
}


public class MyParser
{
	public static void main(String[] args)
	{
		
		NTor alpha = new NTor("字母");
		for(char c='a'; c<='z'; c++) alpha.add(new T(c));
		for(char c='A'; c<='Z'; c++) alpha.add(new T(c));
		
		NTor number = new NTor("数字");
		for(char c='0'; c<='9'; c++) number.add(new T(c));

		NTor operator = new NTor("运算符");
		operator.add(new T('+'));
		operator.add(new T('-'));
		operator.add(new T('*'));
		operator.add(new T('/'));
		
		NTrep space = new NTrep("空白", new T(' '));
				
		NTor space_or_not = new NTor("可能空白");
		space_or_not.add(space);
		space_or_not.add(new Tnull());	
		
		NTrep positive_int = new NTrep("正整数", number);	
		
		NTseq negative_int = new NTseq("负整数");
		negative_int.add(new T('-'));
		negative_int.add(positive_int);
		
		NTor integer = new NTor("整数");
		integer.add(positive_int);
		integer.add(negative_int);
		
		NTseq decimal = new NTseq("小数");
		decimal.add(integer);
		decimal.add(new T('.'));
		decimal.add(positive_int);
		
		NTor real = new NTor("实数");
		real.add(decimal);
		real.add(integer);
		
		NTrep var = new NTrep("变量", alpha);
		
		NTseq func = new NTseq("函数");
		
		NTor param = new NTor("参数");
		param.add(func);
		param.add(var);
		param.add(real);		
		
		NTseq t1 = new NTseq("非第一参数");
		t1.add(new T(','));
		t1.add(space_or_not);
		t1.add(param);
		
		NTor t2 = new NTor("任意数量非第一参数");
		t2.add(new NTrep("",t1));
		t2.add(new Tnull());
		
		NTseq t0 = new NTseq("");
		t0.add(param);
		t0.add(space_or_not);
		t0.add(t2);		
		
		NTor params = new NTor("参数表");
		params.add(t0);
		params.add(new Tnull());
		
		func.add(var);
		func.add(space_or_not);
		func.add(new T('('));
		func.add(space_or_not);
		func.add(params);
		func.add(space_or_not);
		func.add(new T(')'));

		Context context = new Context();
		
		context.data = "abcd( abc, -1.53, xyz(fff,12), abc)";
		context.p = 0;
		
		NTseq a = new NTseq("");
		a.add(space_or_not);
		a.add(func);
		a.add(space_or_not);
		a.add(new Tend());
		
		boolean b = a.parse(context);
		System.out.println(b);
	}
}

