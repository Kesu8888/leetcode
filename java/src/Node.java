public class Node{
    boolean isStar;
    int c;
    int srcP;
    int ptnP;
    int quan;

    public Node(boolean isStar, int c, int srcP, int ptnP, int q) {
        this.isStar = isStar;
        this.c = c;
        this.srcP = srcP;
        this.ptnP = ptnP;
        quan = q;
    }
}
