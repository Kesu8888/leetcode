import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

public class leetcode20 {
    public boolean sol(String s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        Deque<Character> d = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                d.add(c);
                continue;
            }
            if (d.size() > 0 && isSame(d.removeLast(), c)) {
                continue;
            }
            return false;
        }
        if (d.size() > 0) {
            return false;
        }
        return true;
    }
    public boolean isSame(int left, int right) {
        if (left == 40) {
            return right == 41;
        }
        if (left == 91) {
            return right == 93;
        }
        return right == 125;
    }
}
