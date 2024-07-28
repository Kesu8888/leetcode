import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class leetcode208 {
    class node {
        Map<Character, node> next = new HashMap<>();
    }
    node root;
    Set<String> bottle;
    leetcode208() {
        root = new node();
        bottle = new HashSet<>();
    }
    public void insert(String word) {
        if (bottle.contains(word)) {
            return;
        }
        node n = root;
        for (int i = 0; i < word.length(); i++) {
            if (!n.next.containsKey(word.charAt(i))) {
                n.next.put(word.charAt(i), new node());
            }
            n = n.next.get(word.charAt(i));
        }
        bottle.add(word);
    }
    public boolean search(String word) {
        return bottle.contains(word);
    }

    public boolean startsWith(String prefix) {
        node n = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!n.next.containsKey(prefix.charAt(i))) {
                return false;
            }
            n = n.next.get(prefix.charAt(i));
        }
        return true;
    }
}
