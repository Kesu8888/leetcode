import java.util.HashMap;

public class leetcode128 {
    public int sol(int[] nums) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        for (int i : nums) {
            hash.put(i, 1);
        }

        int res = 0;
        for (int i : nums) {
            if (hash.containsKey(i)) {
                res = Math.max(res, hash.remove(i)+upwards(hash, i+1)+downwards(hash, i-1));
            }
        }
        return res;
    }

    public int upwards(HashMap<Integer, Integer> hash, int num) {
        int i = 0;
        while (hash.containsKey(num)) {
            i += hash.remove(num);
            num++;
        }
        return i;
    }
    public int downwards(HashMap<Integer, Integer> hash, int num) {
        int i = 0;
        while (hash.containsKey(num)) {
            i += hash.remove(num);
            num--;
        }
        return i;
    }
}
