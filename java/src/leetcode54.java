import java.util.ArrayList;
import java.util.List;

public class leetcode54 {
    public List<Integer> sol(int[][] matrix) {
        int startX = 0; int endX = matrix.length-1;
        int startY = 0; int endY = matrix[0].length-1;
        List<Integer> l = new ArrayList<>();
        //0=right, 1=down, 2=left, 3=up;
        int turn = 0;
        boolean cont = true;
        while (cont) {
            if (startX == endX || startY == endY) {
                cont = false;
                if (startX == endX) {
                    turn = (turn%2 == 0) ? turn : (turn+1)%4;
                } else {
                    turn = (turn%2 == 1) ? turn : turn+1;
                }
            }
            int temp;
            if (turn == 0) {
                for (int i = startY; i <= endY; i++) {
                    l.add(matrix[startX][i]);
                }
                startX ++;
                temp = startY;
                startY = endY;
                endY = temp;
                turn = (turn+1)%4;
            } else if (turn == 1) {
                for (int i = startX; i <= endX; i++) {
                    l.add(matrix[i][startY]);
                }
                startY --;
                temp = startX;
                startX = endX;
                endX = temp;
                turn = (turn+1)%4;
            } else if (turn == 2) {
                for (int i = startY; i >= endY; i--) {
                    l.add(matrix[startX][i]);
                }
                startX --;
                temp = startY;
                startY = endY;
                endY = temp;
                turn = (turn+1)%4;
            } else {
                for (int i = startX; i >= endX; i--) {
                    l.add(matrix[i][startY]);
                }
                startY ++;
                temp = startX;
                startX = endX;
                endX = temp;
                turn = (turn+1)%4;
            }
        }
        return l;
    }
}
