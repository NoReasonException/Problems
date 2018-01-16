
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// 2 - abc
// 3 - def
// 4 - ghi
// 5 - jkl
// 6 - mno
// 7 - pqrs
// 8 - tuv
// 9 - wxyz

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(Solution("23").toArray()));
    }

    private static ArrayList<java.lang.String> S=null;

    /***
     * Wrapper over Solution2 to return the actual Solution
     * @param str
     * @return
     */
    public static ArrayList<java.lang.String> Solution(java.lang.String str){
        Main.S=new ArrayList<>();
        Solution2(Parser(str,Main.getMapping()),"",0);
        return Main.S;

    }


    /***
     * Actual Recv Algorithm to find all posible words :) !
     * @param ExecutionQueue
     * @param tmp
     * @param st
     */

    private static void Solution2(java.util.ArrayList<ArrayList<Character>> ExecutionQueue,java.lang.String tmp,int st){
        if(st==ExecutionQueue.size()){
            Main.S.add(tmp);
            return;
        }
        for (int i = 0; i < ExecutionQueue.get(st).size(); i++) {
            Solution2(ExecutionQueue,tmp+ExecutionQueue.get(st).get(i),st+1);
        }

    }
    /***
     Parser
     Returns a Queue with mappings
     @param str -> the string to parse
     */
    private static java.util.ArrayList<ArrayList<Character>> Parser(java.lang.String str,ArrayList<ArrayList<Character>> Mapping){
        ArrayList<ArrayList<Character>> retval = new ArrayList<>();
        int parsetmp;
        for (int i = 0; i < str.length(); i++) {
            parsetmp=Integer.parseInt(String.valueOf(str.charAt(i)));
            if(parsetmp<2 || parsetmp>9)throw new IllegalArgumentException();
            retval.add(Mapping.get(parsetmp-2));

        }

        return retval;
    }

    /***
     * Initalization function , returns the digit to characters mapping...
     * @return An 2D ArrayList , The mapping
     */
    private static ArrayList<ArrayList<Character>> getMapping(){
        return new ArrayList<ArrayList<Character>>(){{
            this.add(new ArrayList<Character>(){{
                this.add('a');
                this.add('b');
                this.add('c');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('d');
                this.add('e');
                this.add('f');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('g');
                this.add('h');
                this.add('i');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('j');
                this.add('k');
                this.add('l');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('m');
                this.add('n');
                this.add('o');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('p');
                this.add('q');
                this.add('r');
                this.add('s');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('t');
                this.add('u');
                this.add('v');
            }});
            this.add(new ArrayList<Character>(){{
                this.add('w');
                this.add('x');
                this.add('y');
                this.add('z');
            }});

        }};
    }
}
