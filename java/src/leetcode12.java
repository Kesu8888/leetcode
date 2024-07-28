import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class leetcode12 {
    //Standard math method
    /*static int[] values = {
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
    public String sol(int num) {
        StringBuilder roman = new StringBuilder();
        for (int i = 0; i < values.length && num > 0; i++) {
            while (num >= values[i]) {
                num -= values[i];
                roman.append(symbol[i]);
            }
        }
        return roman.toString();
    }*/

    // Cheat method 2
    /*String sol(int num) {
        String[] ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        String[] tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        String[] hrns = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        String[] ths={"","M","MM","MMM"};

        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }*/
    //Map<Integer, String> map = new HashMap<>(); Stupid method 1
    /*public String sol(int num) {
        map.put(1, "I");
        map.put(5, "V");
        map.put(10, "X");
        map.put(50, "L");
        map.put(100, "C");
        map.put(500, "D");
        map.put(1000, "M");
        int pow = 0;
        String s = "";
        while (num > 0) {
            int v = num%10;
            if (v == 4 || v == 9) {
                s = map.get((int)Math.pow(10, pow)) + map.get((v + 1) * (int)Math.pow(10, pow)) + s;
            } else {
                s = (v >= 5) ? map.get(5 * (int)Math.pow(10, pow)) +
                    map.get((int)Math.pow(10, pow)).repeat(v - 5) + s:
                    map.get((int)Math.pow(10, pow)).repeat(v) + s;
            }
            pow ++;
            num /= 10;
        }
        return s;
    }*/
}
