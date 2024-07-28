import java.util.Comparator;
import java.util.PriorityQueue;

public class leetcode11 {
    public int sol(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;
        while (right - left > 0) {
            int bottleneck = Math.min(height[left], height[right]);
            maxArea = Math.max(maxArea, ((right - left) * bottleneck));
            if (height[left] == bottleneck) {
                left ++;
            } else {
                right --;
            }
        }
        return maxArea;
    }
    // Get a lower runtime solution
    /*public int sol(int[] height) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

    }*/
}
