import java.util.Arrays;

public class leetcode16 {
    public int sol(int[] nums, int target) {
        Arrays.sort(nums);
        int closeAns;
        closeAns = nums[0] + nums[1] + nums[2];
        if (closeAns > target) {
            return closeAns;
        }
        int max = nums[nums.length-1] + nums[nums.length - 2] + nums[nums.length - 3];
        if (max < target) {
            return max;
        }
        for (int i = 0; i < nums.length - 2; i++) {
            //This is to prevent duplicate num
            while (i > 0 && nums[i] == nums[i - 1] && i < nums.length - 2) {
                i ++;
            }
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    closeAns = (Math.abs(target - closeAns) < Math.abs(target - sum)) ? closeAns : sum;
                    j ++;
                    while (j < nums.length && nums[j] == nums[j - 1]) {
                        j ++;
                    }
                } else {
                    closeAns = (Math.abs(target - closeAns) < Math.abs(target - sum)) ? closeAns : sum;
                    k --;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k --;
                    }
                }
            }
        }
        return closeAns;
    }
}
