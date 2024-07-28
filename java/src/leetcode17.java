import java.util.ArrayList;
import java.util.List;

public class leetcode17 {
    public static int[] values = new int[] {
        0, 3, 6, 9, 12, 15, 19, 22
    };
    public static String[] letters = new String[] {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    public List<String> sol(String digits) {
        if (digits.length() < 1) {
            return new ArrayList<>();
        }
        char[] returnStr = new char[digits.length()];
        List<String> ans = new ArrayList<>();
        getCombine(returnStr, ans, digits, 0);
        return ans;
    }
    public void getCombine(char[] str, List<String> ans, String digits, int index) {
        if (index >= digits.length()) {
            ans.add(String.copyValueOf(str));
            return;
        }
        // s is
        int s = digits.charAt(index) - 50;
        String lettersRange = letters[s];
        for (int i = 0; i < lettersRange.length(); i++) {
            str[index] = lettersRange.charAt(i);
            getCombine(str, ans, digits, index + 1);
        }
    }
}
