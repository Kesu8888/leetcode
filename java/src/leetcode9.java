import java.util.ArrayList;

public class leetcode9 {
    public boolean sol(int x) {
        if (x < 0) {
            return false;
        }
        ArrayList<Integer> bits = new ArrayList<>();
        while (x > 0) {
            bits.add(x % 10);
            x = x/10;
        }
        int diff = ((bits.size() % 2) == 0) ? 1 : 0;
        int left = 0;
        int right = bits.size() - 1;
        while (right - left >= diff) {
            if (bits.get(left).equals(bits.get(right))) {
                left ++;
                right --;
            } else {
                return false;
            }
        }
        return true;
    }
}
