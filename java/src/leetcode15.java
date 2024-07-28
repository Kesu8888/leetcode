import java.util.*;

public class leetcode15 {
    public List<List<Integer>> sol(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            while (i > 0 && nums[i] == nums[i - 1] && i < nums.length - 2) {
                i ++;
            }
            int j = i + 1;
            int k = nums.length - 1;
            while (k > j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j ++;
                    k --;
                    while (j < nums.length && nums[j] == nums[j - 1]) {
                        j ++;
                    }
                    while (k > j && nums[k] == nums[k + 1]) {
                        k --;
                    }
                } else if (sum < 0) {
                    j ++;
                    while (j < nums.length && nums[j] == nums[j - 1]) {
                        j ++;
                    }
                } else {
                    k --;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k --;
                    }
                }
            }
        }
        return ans;
    }
}
