enum Table {
    TRUE, FALSE
}
public class leetcode10 {
    Table[][] dp;

    public boolean sol(String s, String p) {
        dp = new Table[s.length() + 1][p.length() + 1];
        return rdp(s.length(), p.length(), s, p);
    }

    //Reverse dp that I wrote for exercise
    public boolean rdp(int i, int j, String text, String pattern) {
        if (dp[i][j] != null) {
            return dp[i][j] == Table.TRUE;
        }

        if (j == 0) {
            return i == 0;
        }
        boolean ans;
        boolean first_match;
            if (pattern.charAt(j - 1) == '*') {
                first_match = i > 0 && (text.charAt(i - 1) == pattern.charAt(j - 2) || pattern.charAt(j - 2) == '.');
                ans = rdp(i, j - 2, text, pattern) || first_match && rdp(i - 1, j, text, pattern);
            } else {
                first_match = i > 0 && text.charAt(i - 1) == pattern.charAt(j - 1) || pattern.charAt(j - 1) == '.';
                ans = first_match && rdp(i - 1, j - 1, text, pattern);
            }

        dp[i][j] = ans ? Table.TRUE : Table.FALSE;
        return ans;
    }
    // normal dp copied from leetcode solution
    /*public boolean dp(int S, int P, String s, String p) {
        // If the result has been computed
        if (table[S][P] != null) {
            return table[S][P] == Table.TRUE;
        }

        boolean ans;
        // Check if P reaches the end
        if (P == p.length()) {
            ans = S == s.length();

        } else {
            //Check whether the char in s matches the char in p
            boolean first_match = (S < s.length() &&
                (p.charAt(P) == s.charAt(S) ||
                    p.charAt(P) == '.'));
            // Check if the next char is '*'.
            if (P + 1 < p.length() && p.charAt(P+1) == '*'){
                // either the star represents 0 elements or many elements, dp until we locate the n elements
                ans = (dp(S, P+2, s, p) ||
                    first_match && dp( S+1, P, s, p));
            } else {
                // check whether the next element of both are match
                ans = first_match && dp(S+1, P+1, s, p);
            }
        }
        table[S][P] = ans ? Table.TRUE : Table.FALSE;
        return ans;
    }*/
}
