public class leetcode13 {
    //Reverse method of leetcode 12
    /*
    static String[] symbol = {
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I"
    };
    static int[] values = {
        1000,
        900,
        500,
        400,
        100,
        90,
        50,
        40,
        10,
        9,
        5,
        4,
        1
    };
    public int sol(String s) {
        StringBuilder Roman = new StringBuilder(s);
        int answer = 0;
        for (int i = symbol.length - 1; i >= 0; i--) {
            while (Roman.length() >= symbol[i].length() &&
                Roman.substring(Roman.length() - symbol[i].length()).equals(symbol[i])) {
                answer += values[i];
                Roman.delete(Roman.length() - symbol[i].length(), Roman.length());
            }
        }
        return answer;
    }*/
    // low runtime method
    public int sol(String s) {
        int n = s.length();
        int prev = 0;
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            char num = s.charAt(i);
            switch (num) {
                case 'M' -> num = 1000;
                case 'D' -> num = 500;
                case 'C' -> num = 100;
                case 'L' -> num = 50;
                case 'X' -> num = 10;
                case 'V' -> num = 5;
                case 'I' -> num = 1;
            }
            //If the current char is smaller than prev char number, it is a subtraction so we minus the prev number.
            if (num < prev) {
                ans -= num;
            } else {
                ans += num;
            }
            prev = num;

        }
        return ans;
    }
}
