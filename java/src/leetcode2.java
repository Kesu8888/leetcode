public class leetcode2 {
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode sol(ListNode l1, ListNode l2) {
        ListNode L1 = l1;
        ListNode L2 = l2;
        ListNode n = new ListNode();
        ListNode answer = n;
        int extra = 0;
        int v1 = L1.val;
        int v2 = L2.val;
        while ((L1 != null) || (L2 != null) || (extra != 0)) {
            int sum = (v1 + v2 + extra) % 10;
            extra = ((v1 + v2 + extra) < 10) ? 0 : 1;
            n.next = new ListNode(sum);
            n = n.next;
            L1 = (L1 != null) ? L1.next : null;
            L2 = (L2 != null) ? L2.next : null;
            v1 = (L1 != null) ? L1.val : 0;
            v2 = (L2 != null) ? L2.val : 0;
        }
        return answer.next;
    }

    public void test() {
        System.out.println("Hello world!");
        leetcode2 a1 = new leetcode2();
        leetcode2.ListNode l1 = new leetcode2.ListNode(0);
        leetcode2.ListNode answer1 = l1;
        for (int i = 0; i < 13; i++) {
            l1.next = new leetcode2.ListNode(i % 10);
            l1 = l1.next;
            System.out.print(l1.val);
        }
        System.out.print("\n");

        leetcode2.ListNode l2 = new leetcode2.ListNode(0);
        leetcode2.ListNode answer2 = l2;
        for (int i = 0; i < 8; i++) {
            l2.next = new leetcode2.ListNode(i % 10);
            l2 = l2.next;
            System.out.print(l2.val);
        }
        System.out.print("\n");

        leetcode2.ListNode answer = a1.sol(answer1.next, answer2.next);
        for (;answer != null; answer = answer.next) {
            System.out.print(answer.val);
        }
    }
}


