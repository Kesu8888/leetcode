import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class leetcode7 {
    public int sol(int x) {
        int posMax = 2147483647;
        int negMax = ~posMax;
        // if sign == 1, sign is negative
        int sign = negMax & x;
        ArrayList<Integer> bits = new ArrayList<>();

        //Extracting bits from x
        if (sign == 0) {
            while (x > 0) {
                bits.add(x % 10);
                x = x/10;
            }
        } else {
            while (x < 0) {
                bits.add(x % 10);
                x = x/10;
            }
        }

        if (bits.size() == 10 && Math.abs(bits.get(0)) > 2) {
            return 0;
        }
        int answer = 0;
        for (int i = 0; bits.size() > 0; i++) {
            answer += (int)Math.pow(10, i) * bits.remove(bits.size() - 1);
        }
        if ((answer & negMax) != sign) {
            return 0;
        }
        return answer | sign;
    }
}
