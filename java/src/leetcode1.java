import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class leetcode1 {
    public int[] sol(int[] nums, int target) {
        int size = nums.length;
        PriorityQueue<numset> min = new PriorityQueue<>(new numsetComparator());
        PriorityQueue<numset> max = new PriorityQueue<>(new rvnumsetComparator());
        //Divided the elements in nums into two half
        int nHalfNum = (target >= 0) ? 0 : 1;
        for (int i = 0; i < size; i++) {
            if (nums[i] < target/2) {
                min.add(new numset(i, nums[i]));
            } else if (nums[i] == target/2) {
                if ((nHalfNum % 2) == 0) {
                    min.add(new numset(i, nums[i]));
                } else {
                    max.add(new numset(i, nums[i]));
                }
                nHalfNum ++;
            } else {
                max.add(new numset(i, nums[i]));
            }
        }

        //
        ArrayList<Integer> returnArray = new ArrayList<>();
        while (min.size() > 0 && max.size() > 0) {
            if ((min.peek().num + max.peek().num) == target) {
                returnArray.add(min.peek().seq);
                returnArray.add(max.peek().seq);
                min.remove();
                max.remove();
                continue;
            }
            if ((min.peek().num + max.peek().num) > target) {
                max.remove();
            } else {
                min.remove();
            }
        }
        Integer[] array = returnArray.toArray(new Integer[returnArray.size()]);
        return returnArray.stream().mapToInt(Integer::intValue).toArray();
    }
    class numset {
        public Integer seq;
        public Integer num;
        numset(int s, int n) {
            seq = s;
            num = n;
        }
    }
    class numsetComparator implements Comparator<numset> {
        @Override
        public int compare(numset o1, numset o2) {
            return o1.num.compareTo(o2.num);
        }
    }
    class rvnumsetComparator implements Comparator<numset> {
        @Override
        public int compare(numset o1, numset o2) {
            return o2.num.compareTo(o1.num);
        }
    }
}
