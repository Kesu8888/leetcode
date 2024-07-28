public class leetcode44 {
    enum Table {TRUE, FALSE};
    Table[][] DP;
    public boolean sol(String s, String p) {
        if (s.length() == 0) {
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) != '*') {
                    return false;
                }
            }
            return true;
        }
        DP = new Table[s.length()+1][p.length()+1];
        return findNext(s.length(), p.length(), s, p);
    }
    public boolean findNext(int i, int j, String s, String p) {
        if (DP[i][j] != null) {
            return DP[i][j] == Table.TRUE;
        }
        if (j == 0) {
            return i == 0;
        }
        boolean ans;
        if (p.charAt(j-1) == '*') {
            if (j == 1) {
                ans = true;
            } else {
                ans = i > 0 && (findNext(i-1, j, s, p) || findNext(i-1, j-1, s, p)) || findNext(i, j-1,s,p);
            }
        } else {
            ans = i>0 && (p.charAt(j-1) == '?' || s.charAt(i-1) == p.charAt(j-1)) && findNext(i-1, j-1, s, p);
        }

        DP[i][j] = ans ? Table.TRUE : Table.FALSE;
        return ans;
    }
}
