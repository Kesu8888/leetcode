import java.util.ArrayList;
import java.util.LinkedList;

public class leetcode8 {
    public int sol(String s) {
        char[] cArray = s.toCharArray();
        int i = 0;
        int max = 0x7fffffff;
        //Searching for first non-blank character
        while (i < cArray.length) {
            if (cArray[i] == 45 | cArray[i] == 43) {
                max = (cArray[i] == 45) ? ~max : max;
                i ++;
                break;
            }
            if (cArray[i] != ' ') {
                break;
            }
            i ++;
        }
        while(i < cArray.length) {
            if (cArray[i] == 48) {
                i ++;
            } else {
                break;
            }
        }

        ArrayList<Integer> bits = new ArrayList<>();
        for (; i < cArray.length; i++) {
            if (cArray[i] >= 48 && cArray[i] <= 57) {
                bits.add(cArray[i] - 48);
            } else {
                break;
            }
        }
        if (bits.size() > 10 || (bits.size() == 10 && Math.abs(bits.get(0)) > 2)) {
            return max;
        }
        long answer = 0;
        int size = bits.size();
        for (i = 0; i < size; i++) {
            answer += Math.pow(10, i) * bits.remove(bits.size() - 1);
        }
        //Check whether overflow
        if (Math.abs(answer) > Math.abs((long)max)) {
            return max;
        }
        return (max > 0) ? (int)answer : ~((int)answer) + 1;
    }
}
