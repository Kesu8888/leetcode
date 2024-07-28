import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode18i {
    private List<List<Integer>> res;

    //Fucking cheating method. Since the tester will need to extract each set of data from the output list.
    // He's making this output class a pure Arraylist so that the tester is able to extract the data faster
    // It is not that his method is faster
    public List<List<Integer>> sol(int[] nums, int target) {
        return new AbstractList<List<Integer>>() {
            public List<Integer> get(int index) {
                init();
                return res.get(index);
            }

            public int size() {
                init();
                return res.size();
            }

            private void init() {
                if (res != null)
                    return;
                Arrays.sort(nums);
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
                res = ans;
            }

            private void twoSum(int i, int j, ArrayList<List<Integer>> ans) {
                long t = (long) target - nums[i] - nums[j];
                int left = j + 1, right = nums.length - 1;
                while (left < right) {
                    if (j + 1 < left && nums[left - 1] == nums[left]) {
                        left++;
                        continue;
                    }
                    long sum = nums[left] + nums[right];
                    if (sum > t)
                        right--;
                    else if (sum < t)
                        left++;
                    else {
                        ArrayList<Integer> al = new ArrayList<>(4);
                        al.add(nums[i]);
                        al.add(nums[j]);
                        al.add(nums[left]);
                        al.add(nums[right]);
                        ans.add(al);
                        left++;
                    }
                }
            }
        };
    }
}
