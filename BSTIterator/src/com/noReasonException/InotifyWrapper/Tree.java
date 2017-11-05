package com.noReasonException.InotifyWrapper;

import java.util.EmptyStackException;
import java.util.Iterator;
import java.util.Stack;

/****
 * Tree implements iterable....
 * This class comes from the definition of exercise....
 *
 */
public class Tree implements Iterable<Tree> {
    Tree left;
    Tree right;
    int val;
    Tree(Tree left,Tree right,int val){
        this.left=left;
        this.right=right;
        this.val=val;
    }

    @Override
    public Iterator<Tree> iterator() {
        return new TreeIterator(this);
    }


}

/***
 * Class StackInfo...
 * We use it to recreate the stack and to remember where to go next  ...
 */
class StackInfo{
    public boolean left=true;
    public boolean center=true;
    public boolean right=true;
    Tree v;
    StackInfo(Tree v){this.v=v;}

}

/***
 * The main Iterator class....
 * @author noReasonException(StefStef)
 * @version 0.0.1
 *
 */
class TreeIterator implements Iterator<Tree>{
    Tree nextNode;                                      //we use it to detect when must raise the hasNext flag...
    private StackInfo curr;                             //current stack pointer..
    private Stack<StackInfo> stack = new Stack<>();     //fake stack
    boolean hasNext=true;                               //has more elements flag...

    @Override
    public boolean hasNext() {
        return hasNext;
    }
    public void goTo(Tree v){                           //push in stack the current frame..(must call next() afterwards)
        this.stack.push(this.makeStackRec(v));
    }
    public void goUp(){
        try{
            this.curr=stack.pop();

        }catch (Exception e){
            this.hasNext=false;
        }
    }
    public StackInfo makeStackRec(Tree v){              //create a stack record to insert...
        StackInfo st = new StackInfo(v);
        if(v.left==null)st.left=false;
        if(v.right==null)st.right=false;
        return st;

    }
    @Override
    public Tree next() {                                //fake wrapper over real next2() , to detect the end of iteration...
        Tree v = this.nextNode;
        try{
            this.nextNode=next2();

        }catch (EmptyStackException e){
            hasNext=false;
        }
        return v;
    }
    public Tree next2() {
        StackInfo st = stack.peek();                    //get current stack frame...
        if(st.left){                                    //if we dont have gone left -> go left!
            st.left=false;                              //mark to to go again...
            goTo(st.v.left);                            //push stack...
            return next2();                             //recall...
        }
        else if(st.center){                             //if we already go left , return center....
            st.center=false;
            return st.v;
        }
        else if(st.right){                              //just like left...
            st.right=false;
            goTo(st.v.right);
            return next2();
        }
        goUp();                                         //if we have gone in all possible places..., goUp
        return next2();
    }
    public TreeIterator(Tree root) {
        this.curr=new StackInfo(root);
        this.stack.push(this.curr);
        this.nextNode=next2();
    }
}
