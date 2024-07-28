import java.util.Arrays;

public class leetcode14 {
    public String sol(String[] strs) {
            if (strs.length == 0) {
                return "";
            }
            if (strs.length == 1) {
                return strs[0];
            }
            Arrays.sort(strs);
            String prefix = "";
            int i = 0;
            while (i < strs[0].length() && i < strs[strs.length-1].length()) {
                if (strs[0].charAt(i) != strs[strs.length-1].charAt(i)) {
                    break;
                }
                i++;
            }
            return strs[0].substring(0, i);
    }
}
