import java.util.Arrays;

public class leetcode5 {
    public String sol(String s) {
        char[] editedS = new char[s.length() + 2];
        //Added a special symbol to the front of the string
        System.arraycopy(s.toCharArray(), 0, editedS, 1, s.length());
        editedS[0] = '-';
        editedS[editedS.length - 1] = '*';
        System.out.println(editedS);

        int[] ASCIIList = new int[200];
        node curNode = new node(1, 1);
        for (int i = 1; i < editedS.length - 1; i++) {
            if (editedS[i] == editedS[i-1]) {
                curNode = getPalindrome(i-1, i, editedS, curNode);
                continue;
            }
            if (editedS[i - 1] == editedS[i + 1]) {
                curNode = getPalindrome(i, editedS, curNode);
            }
        }
        char[] answer = Arrays.copyOfRange(editedS, curNode.start, curNode.start + curNode.size);
        return String.copyValueOf(answer);
    }

    public node getPalindrome(int center, char[] S, node curNode) {
        int distance = 2;
        int max = S.length - center;
        while(distance < max) {
            if (S[center - distance] != S[center + distance]) {
                break;
            }
            distance ++;
        }
        if ((distance-1) * 2 + 1 <= curNode.size) {
            return curNode;
        }
        return new node(center - (distance - 1), (distance - 1) * 2 + 1);
    }

    public node getPalindrome(int center1, int center2, char[] S, node curNode) {
        int distance = 1;
        int max = S.length - center2;
        while (distance < max) {
            if ((S[center1 - distance]) != S[center2 + distance]) {
                break;
            }
            distance ++;
        }
        if ((distance - 1) * 2 + 2 < curNode.size) {
            return curNode;
        }
        return new node(center1 - (distance - 1), (distance  - 1) * 2 + 2);
    }

    class node{
        int start;
        int size;

        node(int start, int size) {
            this.size = size;
            this.start = start;
        }
    }
}
