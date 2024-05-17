import java.util.Arrays;

public class leetcode6 {
    public String sol(String s, int numRows) {
        char[] c = s.toCharArray();
        // compute the number the elements in a zigzag
        int zigzag = (numRows <= 2) ? numRows : numRows + (numRows - 2);
        char[] answer = new char[c.length];
        int size = putChar(0, c, 0, answer, numRows, zigzag);

        int left = 0;
        int right = 0;
        int leftSize = 0;
        while ((1 + left + right) < zigzag) {
            if (left == right) {
                left ++;
                leftSize = putChar(left, c, size, answer, numRows, zigzag);
            } else {
                right ++;
                size = size + leftSize + putChar(zigzag - right, c, size + 1, answer, numRows, zigzag);
            }
        }
        return String.copyValueOf(answer);
    }

    public int putChar(int index, char[] src, int start, char[] dst, int numRows, int zigzag) {
        int interval = (index == 0 | index == numRows - 1) ? 1 : 2;
        int numChar = 0;
        for (int i = index; i < src.length; i += zigzag) {
            dst[start] = src[i];
            start += interval;
            numChar ++;
        }
        return numChar;
    }
}
