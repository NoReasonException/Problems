package com.noReasonException.InotifyWrapper;

import java.util.*;

class Tree {
    Tree right;
    Tree left;
    int val;
    Tree (Tree left,Tree right,int val){this.left=left;this.right=right;this.val=val;}

}
class QueueInf{
    Tree v;
    int level;
    QueueInf(Tree v,int level){this.v=v;this.level=level;}
    @Override
    public String toString(){
        return String.valueOf(level);
    }
}
public class Main {
    public ArrayList<Tree>[]levels;
    int currLevel=-1;
    public static void main(String[] args) {
        Tree one =new Tree(null,null,1);
        Tree six =new Tree(null,null,6);

        Tree twelve =new Tree(null,null,12);
        Tree seventeen =new Tree(null,null,17);

        Tree five  =new Tree(one,six,5);
        Tree fiftteen =new Tree(twelve,seventeen,15);

        Tree ten =new Tree(five,fiftteen,10);
        new Main().BFS(ten);

    }
    public ArrayList<QueueInf> getChilds(QueueInf queueInf){
        ArrayList<QueueInf> retval = new ArrayList<>();
        if(queueInf.v.left!=null)retval.add(new QueueInf(queueInf.v.left,queueInf.level+1));
        if(queueInf.v.right!=null)retval.add(new QueueInf(queueInf.v.right,queueInf.level+1));
        return retval;
    }
    public void initialization(){
        this.levels=new ArrayList[3];
        for (int i = 0; i < 3; i++) {
            this.levels[i]=new ArrayList<>();
        }
    }
    public void BFS(Tree v){
        initialization();
        Queue<QueueInf> queue = new LinkedList<QueueInf>();         //queue
        QueueInf temp=new QueueInf(v,0);                    //add the root to queue
        queue.add(temp);                                            //..

        while(!queue.isEmpty()){
            temp=queue.peek();
            queue.addAll(this.getChilds(temp));
            System.out.println(temp.v.val +" in level "+temp.level);
            this.levels[temp.level].add(temp.v);
            queue.poll();
        }
        end();

    }
    public void end(){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < this.levels[i].size(); j++) {
                System.out.print("["+this.levels[i].get(j).val+"]");
            }
            System.out.println();
        }
    }
}
