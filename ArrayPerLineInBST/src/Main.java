import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

public class Main {

    public static void main(String[] args)
    {
        ArrayList<Integer>[] res=BFS(new ArrayList<Integer>(){{
            this.add(1);
            this.add(3);
            this.add(2);
            this.add(4);
            this.add(null);
            this.add(null);
            this.add(5);
            this.add(6);
            this.add(null);
            this.add(null);
            this.add(7);
        }});
        for (ArrayList<Integer> b: res) {
            System.out.println(Arrays.toString(b.toArray()));
        }
    }
    public static ArrayList<Integer> [] BFS(ArrayList<Integer> arr){
        ArrayList<Integer> traversal[]=new ArrayList[(int)Math.sqrt(arr.size())+1];
        int tmp;
        for (int i = 0; i <arr.size() ; i++) {
            tmp=(int)Math.sqrt(i);
            if(traversal[tmp]==null){
                traversal[tmp]=new ArrayList<Integer>();
            }
            if(arr.get(i)!=null){
                traversal[tmp].add(arr.get(i));

            }
        }
        return traversal;
    }
}