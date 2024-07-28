import java.util.*;

public class leetcode46 {
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> sol(int[] nums) {
        backtrack(nums, 0);
        return res;
    }
    public void backtrack(int[] nums, int idx){
        if(idx == nums.length){
            List<Integer> list = new ArrayList<>();
            for(int i=0; i<nums.length; i++) list.add(nums[i]);
            res.add(list);
            return;
        }
        for(int i = idx; i < nums.length; i++){
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
