import java.util.ArrayList;

public class Main {
    public ArrayList<Tree> b = new ArrayList<>();
    public ArrayList<String> solutions = new ArrayList<>();
    public int index=0;
    public StringBuilder tempBuilder=new StringBuilder();
    public static void main(String args[]) {
        Tree one = new Tree(null, null, 1);
        Tree six = new Tree(null, null, 6);
        Tree twelve = new Tree(null, null, 12);
        Tree seventeen = new Tree(null, null, 17);
        Tree five = new Tree(one, six, 5);
        Tree fiftteen = new Tree(twelve, seventeen, 15);
        Tree ten = new Tree(five, fiftteen, 10);
        for (String paths:new Main().getSolutions(ten)) {
            System.out.println(paths);
        }
    }
    public void dfs(Tree v){
        if (v.left==null && v.right==null){
            for (int i = 0; i < b.size(); i++) {
                tempBuilder.append(b.get(i).val+"->");
            }
            tempBuilder.append(v.val);
            solutions.add(tempBuilder.toString());
            tempBuilder.setLength(0);
            index+=1;
            return;
        }
        b.add(v);
        if(v.left!=null){dfs(v.left); }
        if(v.right!=null)dfs(v.right);
        if(b.contains(v))b.remove(v);
    }

    public ArrayList<String> getSolutions(Tree v) {
        this.dfs(v);
        return solutions;
    }
}

class Tree {
    Tree right;
    Tree left;
    int val;
    Tree (Tree left,Tree right,int val){this.left=left;this.right=right;this.val=val;}

}