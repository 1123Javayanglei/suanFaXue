
import java.util.*;

public class Maze
{
	private char[][] data;
	private Pos entry;
	private Pos exit;
	private Set solve = new HashSet(); //ÕÒµ½µÄ½â 
	
	class Pos
	{
		int i;
		int j;
		public Pos(int x, int y){ i=x; j=y;}
		public int hashCode() { return i * 1000 + j; }
		public boolean equals(Object x){
			if(x instanceof Pos == false) return true;
			Pos p = (Pos)x;
			return p.i == i && p.j == j;
		}
	}
	
	private void getStdInput()
	{
		Scanner scan = new Scanner(System.in);
		List lst = new ArrayList();
		
		for(;;){	
			try{
				lst.add(scan.nextLine().toCharArray());
			}
			catch(Exception e){	break;}
		}
		
		System.out.println(lst.size());
		data = new char[lst.size()][];
		for(int i=0; i<data.length; i++){ 
			data[i] = (char[])lst.get(i);
			for(int j=0; j<data[i].length; j++){
				if(data[i][j]=='A') entry = new Pos(i,j);
				if(data[i][j]=='B') exit = new Pos(i,j);
			}
		}
	}
	
	private void show()
	{
		for(int i=0; i<data.length; i++){
			for(int j=0; j<data[i].length; j++){
				char c = data[i][j];
				if(c=='.' && solve.contains(new Pos(i,j))) c = 'x';
				System.out.print( c + " ");
			}
			System.out.println();
		}
	}
	
	private boolean go(Pos cur, Set path)
	{
		if(cur.equals(exit)) return true;
		path.add(cur);
		
		Pos[] t = {new Pos(cur.i,cur.j-1), new Pos(cur.i, cur.j+1), 
			new Pos(cur.i-1,cur.j), new Pos(cur.i+1,cur.j)};
			
		for(int i=0; i<t.length; i++){
			try{
				if(data[t[i].i][t[i].j]!='#' && path.contains(t[i])==false)
					if(go(t[i],path)) { 
						solve.add(cur);
						return true;
					}
			}
			catch(Exception e){ }
		}
					
		return false;
	}
	
	private void go()
	{
		Set path = new HashSet();
		solve = new HashSet();
		go(entry,path);
	}
	
	public static void main(String[] args)
	{
		Maze a = new Maze();
		a.getStdInput();
		a.show();
		a.go();
		System.out.println("----------------------");
		a.show();
	}
}