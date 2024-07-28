import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class leetcode47 {
    Set<List<Integer>> res = new HashSet<>();
    public List<List<Integer>> sol(int[] nums) {
        backtrack(nums, 0);
        return res.stream().toList();
    }
    public void backtrack(int[] nums, int idx){
        if(idx == nums.length){
            List<Integer> list = new ArrayList<>();
            for(int i=0; i<nums.length; i++) list.add(nums[i]);
            res.add(list);
            return;
        }
        for(int i = idx; i < nums.length; i++){
            if (i != idx && nums[i] == nums[idx]) {
                continue;
            }
            swap(nums, idx, i);
            backtrack(nums, idx+1);
            swap(nums, idx, i);
        }
    }
    public void swap(int[] arr, int idx, int i){
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}
