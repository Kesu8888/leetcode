import java.security.KeyPair;
import java.util.HashMap;
import java.util.Map;

public class leetcode64 {
    Map<String, Integer> table = new HashMap<>();
    public int sol(int[][] grid) {
        return (getNext(0, 0, grid));
    }
    public int getNext(int i, int j, int[][] grid) {
        String key = Integer.toString(i) + ">" + Integer.toString(j);
        if (table.containsKey(key)) {
            return table.get(key);
        }
        int bottom, right;
        if (i == grid.length - 1 || j == grid[0].length - 1) {
            if (i == grid.length - 1 && j == grid[0].length - 1) {
                table.put(key, grid[i][j]);
                return grid[i][j];
            }
            int v;
            if (i == grid.length - 1) {
                v = grid[i][j] + getNext(i, j + 1, grid);
                table.put(key, v);
                return v;
            }
            v = grid[i][j] + getNext(i + 1, j, grid);
            table.put(key, v);
            return v;
        }
        bottom = getNext(i + 1, j, grid);
        right = getNext(i, j + 1, grid);
        int value = Math.min(bottom, right) + grid[i][j];
        table.put(key, value);
        return value;
    }
}
