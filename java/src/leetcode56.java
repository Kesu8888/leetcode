import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class leetcode56 {
    public int[][] sol(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });

        int left = intervals[0][0];
        int right = intervals[0][1];
        int seq = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] > right) {
                intervals[seq][0] = left;
                intervals[seq][1] = right;
                left = intervals[i][0];
                right = intervals[i][1];
                seq++;
            } else
                right = Math.max(right, intervals[i][1]);
        }
        intervals[seq][0] = left;
        intervals[seq][1] = right;
        return Arrays.copyOfRange(intervals, 0, seq+1);
    }
}
