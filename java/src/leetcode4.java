public class leetcode4 {
    public double sol(int[] nums1, int[] nums2) {
        int[] mergedArray = new int[nums1.length + nums2.length];
        int sequence1 = 0;
        int sequence2 = 0;
        int i = 0;
        
        while ((sequence1 < nums1.length) && (sequence2 < nums2.length)) {
            if (nums1[sequence1] < nums2[sequence2]) {
                mergedArray[i] = nums1[sequence1];
                sequence1++;
            } else {
                mergedArray[i] = nums2[sequence2];
                sequence2++;
            }
            i++;
        }
        
        int sequence;
        int[] remainingArray;
        if (sequence1 < nums1.length) {
            remainingArray = nums1;
            sequence = sequence1;
        } else {
            remainingArray = nums2;
            sequence = sequence2;
        }
        
        for (; i < mergedArray.length; i++) {
            mergedArray[i] = remainingArray[sequence];
            sequence ++;
        }

        if (mergedArray.length < 1) {
            return 0;
        }

        if ((mergedArray.length % 2) == 0) {
            return (double) (mergedArray[mergedArray.length / 2] + mergedArray[mergedArray.length / 2 - 1]) /2;
        }
        return (double) mergedArray[mergedArray.length/2];
    }
}
