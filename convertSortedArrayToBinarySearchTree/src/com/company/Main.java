// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
package com.company;

import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.List;

/***
 * Given by definition
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
    public java.lang.StringBuilder instance;

}

public class Main {

    public static void main(String[] args) {
	    TreeNode e = new TreeNode(0);
	    ArrayList<Integer> inp = new ArrayList<Integer>(){{
	        this.add(3);
            this.add(10);
            this.add(17);
            this.add(21);
            this.add(36);
            this.add(132);
            this.add(246);
            this.add(256);

        }};
	    Solve(inp);
    }

    /***
     * Basically we reverse the Binary search algorithm to create the balanced tree :)
     * @param ref   Reference to root
     * @param list  Reference to list
     * @param st    List start index
     * @param end   List end index
     */
    public static void Solve1(TreeNode ref,List<Integer> list,int st,int end) {
        int ind = (st + end) / 2;
        ref.val = list.get(ind);
        if (ind != ((st + ind) / 2)) Solve1(ref.left = new TreeNode(0), list, st, ind);
        if (ind != ((ind + end) / 2)) Solve1(ref.right = new TreeNode(0), list, ind + 1, end);
    }

    /***
     * Wrapper over Solve1 , The actual algorithm
     * @param input , the List
     * @return the balanced tree
     */
    public static TreeNode Solve(List<Integer> input){
        TreeNode tn = new TreeNode(0);
        Solve1(tn,input,0,input.size());
        return tn;
    }
}
