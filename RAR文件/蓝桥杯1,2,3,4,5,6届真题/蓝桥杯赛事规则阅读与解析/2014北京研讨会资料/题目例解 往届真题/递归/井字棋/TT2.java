
import java.util.*;

public class TT2
{
	private Scanner scan;
	Set set_all;  // ����λ��
	Set[] set_xo; // ˫���Ѿ����ӵ�λ��
	int igo;  //������Ȩһ��������
	Set[] set_win; //����Ӯ���������о���
	int iAI;  //��AI����һ��
	int last_step; // ���һ����������
	
	public TT2()
	{
		scan = new Scanner(System.in);
		
		set_all = new HashSet();
		for(int i=0; i<9; i++) set_all.add(i);
		
		set_xo = new Set[2];
		set_xo[0] = new HashSet();
		set_xo[1] = new HashSet();
		igo = 0;
		
		int[][] tmp = {{0,1,2},{3,4,5},{6,7,8},
			{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
		set_win = new Set[tmp.length];
		for(int i=0; i<tmp.length; i++){
			set_win[i] = new HashSet();
			for(int j=0; j<tmp[i].length; j++) set_win[i].add(tmp[i][j]);
		}
		
		iAI = -1;  // AI������
		last_step = -1;  // ��û�����һ��
	}
	
	// >0 ��Ӯ <0���� =0 ƽ��
	private int tryAIgo()
	{
		if(set_all.size() == set_xo[0].size() + set_xo[1].size()) return 0;
		
		Set t = new HashSet(); 
		t.addAll(set_all);
		t.removeAll(set_xo[0]);
		t.removeAll(set_xo[1]);
		
		int rr = -1; //�������
		for(Object k: t){
			set_xo[igo].add(k); //����
			try{
				if(test_finish()==igo) return 1;
				
				igo = (igo+1)%2;
				try{
					int r = tryAIgo();
					if(r<0) return 1;
					if(r==0) rr = 0;  // ����ƽ���߷�
				}
				finally{
					igo = (igo+1)%2;  //����
				}
			}
			finally{
				set_xo[igo].remove(k);
			}
		}
		
		return rr;
	}
	
	// ��������
	private int getAIresult()
	{
		Set t = new HashSet(); 
		t.addAll(set_all);
		t.removeAll(set_xo[0]);
		t.removeAll(set_xo[1]);
		
		List win = new ArrayList();  // ��¼����Ӯ���з�
		List tie = new ArrayList();  // ��¼����ƽ���з�
		
		for(Object k: t){
			set_xo[igo].add(k); //����
			try{
				if(test_finish()==igo){ 
					win.add(k);
					continue;
				}
				
				igo = (igo+1)%2;
				try{
					int r = tryAIgo();
					if(r<0) win.add(k);
					if(r==0) tie.add(k);
				}
				finally{
					igo = (igo+1)%2;  //����
				}
			}
			finally{
				set_xo[igo].remove(k);
			}
		}
		
		
		if(win.size()>0) return (Integer)win.get((int)(Math.random() * win.size()));
		
		if(tie.size()>0) return (Integer)tie.get((int)(Math.random() * tie.size()));
		
		//��Ȼ���������и����������Կ��ߣ����������һ�����ڴ�����ʧ��
		return randomGo();
	}	
	
	private int randomGo()
	{
		if(set_all.size() == set_xo[0].size() + set_xo[1].size()) return -1;

		List t = new ArrayList();	
		t.addAll(set_all);
		t.removeAll(set_xo[0]);
		t.removeAll(set_xo[1]);
		return (Integer)t.get((int)(Math.random() * t.size()));
	}
	
	private void show()
	{
		for(int i=0; i<9; i++){
			if(i%3==0) System.out.println();
			char c = '.';
			if(set_xo[0].contains(i)) c = 'x';
			if(set_xo[1].contains(i)) c = 'o';
			if(i == last_step) c -= 32;
			System.out.print(c + " ");
		}
		System.out.println();
	}
	
	private int getPlayerInput()
	{
		char c = 'x';
		if(igo==1) c = 'o';
		for(;;){
			try{
				System.out.print("��" + c + "�����壺");
				int n = (iAI==igo)?
					getAIresult() :
					Integer.parseInt(scan.nextLine());
				if(n<0) return n; // ����
				if(set_all.contains(n)==false) throw new Exception("");
				if(set_xo[0].contains(n) || set_xo[1].contains(n)) throw new Exception("");
				return n;
			}
			catch(Exception e){
				System.out.println("����ȷ������λ��....");
			}
		}
	}
	

	// 0,1����ʤ���ֳ���2��ȫ������û��ʤ����ƽ�֣�-1������ʤ�������Լ�����
	private int test_finish()
	{
		for(int i=0; i<set_win.length; i++){
			if(set_xo[0].containsAll(set_win[i])) return 0; // xʤ
			if(set_xo[1].containsAll(set_win[i])) return 1; // oʤ
		}
		
		if(set_xo[0].size() + set_xo[1].size() == set_all.size()) return 2; //ƽ��
		
		return -1; //����
	}
	
	// ����AI������һ��
	public void setAI(int n)
	{
		if(n>1) return;
		iAI = n;
	}
	
	public void start()
	{
		for(;;){
			show();
			int r = test_finish(); //����Ƿ����Ӧ�ý���
			if(r==0) System.out.println("x��ʤ����");
			if(r==1) System.out.println("o��ʤ����");
			if(r==2) System.out.println("ƽ�ֽ�����");
			if(r>=0) break;
			
			int pi = getPlayerInput();
			
			if(pi<0){
				char c = igo==0 ? 'x' : 'o';
				System.out.println(c + "����������Ϸ������");
				break;
			}
			
			set_xo[igo].add(pi);
			last_step = pi;
			igo = (igo+1)%2;
		}
	}
	
	private static void welcome()
	{
		System.out.println("----------------");
		System.out.println("��������Ϸ  coded by gyhang");
		System.out.println("�Ź����� 0~8 �����ֱ�ʾ��");
		System.out.println("0 1 2");
		System.out.println("3 4 5");
		System.out.println("6 7 8");
		System.out.println("x����o���������壬x�����ߣ�����һ��ֱ�ߵ�һ����ʤ��");
		System.out.println("------------------------------------------------------");
	}
	
	public static void main(String[] args)
	{
		welcome();
		TT2 a = new TT2();
		a.setAI(0);  //��������
		//a.setAI(1);  //������
		//a.setAI(-1);  //����������
		a.start();
	}
}