import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class leetcode1 {
    public int[] sol(int[] nums, int target) {
        for (int i = 1; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                if (nums[j] + nums[j - i] == target) {
                    return new int[]{j, j - i};
                }
            }
        }
        return null;
    }
}
