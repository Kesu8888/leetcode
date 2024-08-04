import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;

public class leetcode150 {
    public int sol(String[] tokens) {
        Stack<Integer> list=new Stack<>();
        for(String s:tokens){
            if("+".equals(s)||"-".equals(s)||"*".equals(s)||"/".equals(s)) list.push(calc(list,s));
            else list.add(Integer.valueOf(s));
        }
        return list.pop();
    }

    public int calc(Stack<Integer> list,String s){
        int temp1=list.pop();
        int temp2=list.pop();
        if("+".equals(s)) return temp2+temp1;
        if("-".equals(s)) return temp2-temp1;
        if("*".equals(s)) return temp2*temp1;
        else return temp2/temp1;
    }
}
