import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class leetcode19 {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
    }
    public ListNode sol(ListNode head, int n) {
        if (head.next == null) {
            return null;
        }
        ArrayList<ListNode> l = new ArrayList<>();
        l.add(head);
        while (head.next != null) {
            head = head.next;
            l.add(head);
        }
        int index = l.size() - n;
        if (index == 0) {
            return l.get(1);
        }
        l.get(index - 1).next = l.get(index).next;
        return l.get(0);
    }
}
