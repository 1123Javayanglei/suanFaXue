
import java.util.*;

public class TT2
{
	private Scanner scan;
	Set set_all;  // 所有位置
	Set[] set_xo; // 双方已经落子的位置
	int igo;  //有走棋权一方的索引
	Set[] set_win; //所有赢棋子力排列局面
	int iAI;  //让AI持哪一方
	int last_step; // 最后一步走在哪里
	
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
		
		iAI = -1;  // AI不参与
		last_step = -1;  // 还没有最后一步
	}
	
	// >0 必赢 <0必输 =0 平局
	private int tryAIgo()
	{
		if(set_all.size() == set_xo[0].size() + set_xo[1].size()) return 0;
		
		Set t = new HashSet(); 
		t.addAll(set_all);
		t.removeAll(set_xo[0]);
		t.removeAll(set_xo[1]);
		
		int rr = -1; //假设必输
		for(Object k: t){
			set_xo[igo].add(k); //试走
			try{
				if(test_finish()==igo) return 1;
				
				igo = (igo+1)%2;
				try{
					int r = tryAIgo();
					if(r<0) return 1;
					if(r==0) rr = 0;  // 发现平局走法
				}
				finally{
					igo = (igo+1)%2;  //回溯
				}
			}
			finally{
				set_xo[igo].remove(k);
			}
		}
		
		return rr;
	}
	
	// 机器走棋
	private int getAIresult()
	{
		Set t = new HashSet(); 
		t.addAll(set_all);
		t.removeAll(set_xo[0]);
		t.removeAll(set_xo[1]);
		
		List win = new ArrayList();  // 记录所有赢局招法
		List tie = new ArrayList();  // 记录所有平局招法
		
		for(Object k: t){
			set_xo[igo].add(k); //试走
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
					igo = (igo+1)%2;  //回溯
				}
			}
			finally{
				set_xo[igo].remove(k);
			}
		}
		
		
		if(win.size()>0) return (Integer)win.get((int)(Math.random() * win.size()));
		
		if(tie.size()>0) return (Integer)tie.get((int)(Math.random() * tie.size()));
		
		//虽然机器智能判负，但棋盘仍可走，可以随机走一步，期待对手失误。
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
				System.out.print("请" + c + "方走棋：");
				int n = (iAI==igo)?
					getAIresult() :
					Integer.parseInt(scan.nextLine());
				if(n<0) return n; // 认输
				if(set_all.contains(n)==false) throw new Exception("");
				if(set_xo[0].contains(n) || set_xo[1].contains(n)) throw new Exception("");
				return n;
			}
			catch(Exception e){
				System.out.println("不正确的输入位置....");
			}
		}
	}
	

	// 0,1：有胜负分出，2：全部下完没分胜负，平局，-1：尚无胜负，可以继续下
	private int test_finish()
	{
		for(int i=0; i<set_win.length; i++){
			if(set_xo[0].containsAll(set_win[i])) return 0; // x胜
			if(set_xo[1].containsAll(set_win[i])) return 1; // o胜
		}
		
		if(set_xo[0].size() + set_xo[1].size() == set_all.size()) return 2; //平局
		
		return -1; //继续
	}
	
	// 设置AI持有哪一方
	public void setAI(int n)
	{
		if(n>1) return;
		iAI = n;
	}
	
	public void start()
	{
		for(;;){
			show();
			int r = test_finish(); //检测是否棋局应该结束
			if(r==0) System.out.println("x方胜出！");
			if(r==1) System.out.println("o方胜出！");
			if(r==2) System.out.println("平局结束！");
			if(r>=0) break;
			
			int pi = getPlayerInput();
			
			if(pi<0){
				char c = igo==0 ? 'x' : 'o';
				System.out.println(c + "方放弃！游戏结束！");
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
		System.out.println("井字棋游戏  coded by gyhang");
		System.out.println("九宫格用 0~8 的数字表示：");
		System.out.println("0 1 2");
		System.out.println("3 4 5");
		System.out.println("6 7 8");
		System.out.println("x方与o方轮流走棋，x方先走，连成一条直线的一方获胜。");
		System.out.println("------------------------------------------------------");
	}
	
	public static void main(String[] args)
	{
		welcome();
		TT2 a = new TT2();
		a.setAI(0);  //机器先走
		//a.setAI(1);  //人先走
		//a.setAI(-1);  //机器不参与
		a.start();
	}
}