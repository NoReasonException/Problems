package com.company;
// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses
// have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house,
// determine the maximum amount of money you can rob tonight without alerting the police.

import java.awt.*;
import java.lang.reflect.Array;
import java.util.*;

class Houses{
    int money;
    int ind;
    Houses(int money,int index){this.money=money;this.ind=index;}
    @Override
    public java.lang.String toString(){
        return "House : "+ind +"With "+this.money+" Money (L)";
    }
}
public class Main {

    public static void main(String[] args) {


        ArrayList<Integer> input = new ArrayList<Integer>(){{
            this.add(299);
            this.add(2);
            this.add(3);
            this.add(7);
            this.add(6);
            this.add(9);
            this.add(8);
            this.add(4);
            this.add(5);
        }};
        Solve(input);
    }
    public static int Solve(ArrayList<Integer> input){
        ArrayList<Houses> h = new ArrayList<>();
        if(input.size()==0)return 0;
        if(input.size()==1)return input.get(0);
        for (int i = 0; i < input.size(); i++) {
            h.add(new Houses(input.get(i),i));
        }
        Collections.sort(h,new Comparator<Houses>(){
            public int compare(Houses house1,Houses house2) {
                if(house1.money>house2.money)return -1;
                if(house1.money<house2.money)return 1;
                return 0;
            }
        });
        int sum=h.get(0).money;
        Houses prev=h.get(0);
        System.out.println(prev);
        Houses curr;
        for (int i = 1; i < h.size(); i++) {
            curr=h.get(i);
            if(curr.ind+1!=prev.ind && curr.ind-1!=prev.ind){
                sum+=curr.money;
                System.out.println(curr);
                prev=curr;
            }

        }
        System.out.println(sum);
        return sum;

    }
}
