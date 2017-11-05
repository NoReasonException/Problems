import java.util.ArrayList;

public class Main {
    public ArrayList<Tree> b = new ArrayList<>();
    public ArrayList<ArrayList<Tree>> solutions = new ArrayList<ArrayList<Tree>>();
    public int index=0;
    public static void main(String args[]) {
        Tree one = new Tree(null, null, 1);
        Tree six = new Tree(null, null, 6);

        Tree twelve = new Tree(null, null, 12);
        Tree seventeen = new Tree(null, null, 17);

        Tree five = new Tree(one, six, 5);
        Tree fiftteen = new Tree(twelve, seventeen, 15);

        Tree ten = new Tree(five, fiftteen, 10);
        Main b=new Main();
        b.dfs(ten);
        b.printSol();

    }
    public void dfs(Tree v){
        if (v.left==null && v.right==null){
            solutions.add(new ArrayList<>());
            solutions.get(index).addAll(b);
            solutions.get(index).add(v);
            index+=1;
            return;
        }
        b.add(v);
        if(v.left!=null){dfs(v.left); }
        if(v.right!=null)dfs(v.right);
        if(b.contains(v))b.remove(v);
    }
    public void printSol(){
        for (int i = 0; i < solutions.size(); i++) {
            for (int j = 0; j < solutions.get(i).size(); j++) {
                System.out.print(solutions.get(i).get(j).val+"->");
            }System.out.println();

        }
    }
}

class Tree {
    Tree right;
    Tree left;
    int val;
    Tree (Tree left,Tree right,int val){this.left=left;this.right=right;this.val=val;}

}