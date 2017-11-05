package com.noReasonException.InotifyWrapper;

import java.util.Iterator;

public class Main {

    public static void main(String[] args) {
        Tree one =new Tree(null,null,1);
        Tree six =new Tree(null,null,6);

        Tree twelve =new Tree(null,null,12);
        Tree seventeen =new Tree(null,null,17);

        Tree five  =new Tree(one,six,5);
        Tree fiftteen =new Tree(twelve,seventeen,15);

        Tree ten =new Tree(five,fiftteen,10);

        Iterator<Tree> e = new TreeIterator(ten);
        for (Tree v:five) {
            System.out.println(v.val);
        }
    }
}
