import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class leetcode3 {
    public int sol(String s) {
        char[] charArray = s.toCharArray();
        int maxLength = 0;
        int[] ASCIIList = new int[200];
        List<Integer> addedCharList = new LinkedList<>();
        //Initialize the charList
        Arrays.fill(ASCIIList, -1);

        int lastDupChar = 0;
        for (int i = 0; i < charArray.length; i++) {
            int ASCIICode = charArray[i];
            if (ASCIIList[ASCIICode] >= 0) {
                int curLength = i - lastDupChar;
                maxLength = Math.max(curLength, maxLength);
                int originalLastDup = lastDupChar;
                lastDupChar = ASCIIList[ASCIICode] + 1;
                ASCIIList = ArrayRecover(ASCIIList, addedCharList, (ASCIIList[ASCIICode] + 1) - originalLastDup);

            }
            addedCharList.add(ASCIICode);
            ASCIIList[ASCIICode] = i;
        }

        maxLength = Math.max(maxLength, (charArray.length - lastDupChar));
        return maxLength;
    }

    public int[] ArrayRecover(int[] ASCIIList, List<Integer> addedCharList, int number) {
        for (int i = 0;i < number; i++) {
            ASCIIList[addedCharList.remove(0)] = -1;
        }
        return ASCIIList;
    }

}
