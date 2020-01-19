
/*
  Interpreter ģʽ���ڴʷ�����
  
  �԰Ϳ�˹��ʽ���з���
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

// ����ţ���ʾ������ֹ
class Tend implements EP
{
	public boolean parse(Context context)
	{
		return context.p >= context.data.length();
	}	
}

// ���ս������ʾ����Ҫ�κ�ƥ��
class Tnull implements EP
{
	public boolean parse(Context context)
	{
		return true;
	}	
}

// �ս����ʵ�ڵ���ĸ���������
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

// ���ս�����ں�Ԫ�ص�"����"��ϣ�
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
				// �������Ҫ�ʻ㣬����˴ʻ�
				if(_name.equals("����")){
					String s = "������" + context.data.substring(old, context.p);
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

// ���ս�����ں�Ԫ�ص�˳����ϣ�
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
		
		// -------- ���� 
		// �������Ҫ�ʻ㣬����˴ʻ�
		if(_name.equals("����")){
			String s = "������" + context.data.substring(old, context.p);
			System.out.println(s);
		}
		// -------- ����end

		return true;
	}
}

// ���ս��(ĳ�����ʽ��1�λ����ظ�)
class NTrep implements EP
{
	private NTseq _me;  // ����ʹ����ϣ������Ǽ̳�
	
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
		
		NTor alpha = new NTor("��ĸ");
		for(char c='a'; c<='z'; c++) alpha.add(new T(c));
		for(char c='A'; c<='Z'; c++) alpha.add(new T(c));
		
		NTor number = new NTor("����");
		for(char c='0'; c<='9'; c++) number.add(new T(c));

		NTor operator = new NTor("�����");
		operator.add(new T('+'));
		operator.add(new T('-'));
		operator.add(new T('*'));
		operator.add(new T('/'));
		
		NTrep space = new NTrep("�հ�", new T(' '));
				
		NTor space_or_not = new NTor("���ܿհ�");
		space_or_not.add(space);
		space_or_not.add(new Tnull());	
		
		NTrep positive_int = new NTrep("������", number);	
		
		NTseq negative_int = new NTseq("������");
		negative_int.add(new T('-'));
		negative_int.add(positive_int);
		
		NTor integer = new NTor("����");
		integer.add(positive_int);
		integer.add(negative_int);
		
		NTseq decimal = new NTseq("С��");
		decimal.add(integer);
		decimal.add(new T('.'));
		decimal.add(positive_int);
		
		NTor real = new NTor("ʵ��");
		real.add(decimal);
		real.add(integer);
		
		NTrep var = new NTrep("����", alpha);
		
		NTseq func = new NTseq("����");
		
		NTor param = new NTor("����");
		param.add(func);
		param.add(var);
		param.add(real);		
		
		NTseq t1 = new NTseq("�ǵ�һ����");
		t1.add(new T(','));
		t1.add(space_or_not);
		t1.add(param);
		
		NTor t2 = new NTor("���������ǵ�һ����");
		t2.add(new NTrep("",t1));
		t2.add(new Tnull());
		
		NTseq t0 = new NTseq("");
		t0.add(param);
		t0.add(space_or_not);
		t0.add(t2);		
		
		NTor params = new NTor("������");
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

