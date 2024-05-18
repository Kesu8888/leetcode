public class leetcode10 {
    public boolean sol(String s, String p) {
        char[] src = s.toCharArray();
        char[] ptn = p.toCharArray();

        int i1 = src.length - 1;
        int i2 = ptn.length - 1;

        int[] starChar = new int[]{ptn.length, 0};
        while ((i1 >= 0) && (i2 >= 0)) {
            if (ptn[i2] == 42) {
                starChar[0] = i2;
                int[] position = starChar(src, i1, ptn, i2);
                starChar[1] = i1 - position[0];
                i1 = position[0];
                i2 = position[1];
                continue;
            }
            if (!compare(src[i1], ptn[i2])) {
                if ()
                return false;
            }
            i1 --;
            i2 --;
        }

        if (i1 < 0 && i2 < 0) {
            return true;
        }
        if (i2 < 0) {
            return false;
        }
        while (i2 >= 0) {
            if (ptn[i2] == 42) {
                i2 = i2 - 2;
            } else {
                return false;
            }
        }
        return true;
    }

    public boolean compare(int i1, int i2) {
        if (i2 == 46) {
            return true;
        }
        return i1 == i2;
    }

    public int[] starChar(char[] src, int i1, char[] ptn, int i2) {
        int prev = ptn[i2 - 1];
        int[] ret = new int[2];
        while (i1 >= 0) {
            if (!compare(src[i1], prev)) {
                ret[0] = i1;
                ret[1] = i2 - 2;
                return ret;
            }
            i1 --;
        }
        ret[0] = i1;
        ret[1] = i2 - 2;
        return ret;
    }
}
