import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode18 {
    //Brute solution
    public int[] nums;
    public int target;
    public List<List<Integer>> sol(int[] nums, int target) {
        Arrays.sort(nums);
        this.nums = nums;
        this.target = target;
        ArrayList<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.length; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                twoSum(i, j, ans);
            }
        }
        return ans;
    }
    public void twoSum(int i, int j, List<List<Integer>> ans) {
        long rem = (long)target - nums[i] - nums[j];
        int k = j + 1;
        int l = nums.length - 1;
        while (k < l) {
            long sum = nums[k] + nums[l];
            if (sum == rem) {
                ans.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                k ++;
                l --;
                while (k < nums.length && nums[k] == nums[k - 1]) {
                    k ++;
                }
                while (l > k && nums[l] == nums[l + 1]) {
                    l --;
                }
            } else if (sum < rem) {
                k ++;
                while (k < nums.length && nums[k] == nums[k - 1]) {
                    k ++;
                }
            } else {
                l --;
                while (l > k && nums[l] == nums[l + 1]) {
                    l --;
                }
            }
        }
    }
}
