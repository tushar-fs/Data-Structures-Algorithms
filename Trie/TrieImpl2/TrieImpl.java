package Trie.TrieImpl2;

public class TrieImpl {
    private TrieNode root;

    public TrieImpl() {
        this.root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char x = word.charAt(i);
            if (!node.containsKey(x)) {
                node.putKey(x);
            }
            node = node.getKey(x);
            node.incrementPrefixWith();
        }
        node.incrementEndsWith();
    }

    private TrieNode findNode(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char x = word.charAt(i);
            if (!node.containsKey(x)) {
                return null;
            }
            node = node.getKey(x);
        }
        return node;
    }

    public void erase(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char x = word.charAt(i);
            if (!node.containsKey(x))
                return;
            node.removeKey(x);
            node = node.getKey(x);
        }
        node.decrementEndsWith();
    }

    public int countWordEqualTo(String word) {
        TrieNode node = findNode(word);
        return node != null ? node.getEndsWithCount() : 0;
    }

    public int countWordStartsWith(String word) {
        TrieNode node = findNode(word);
        return node != null ? node.getPrefixWithCount() : 0;
    }

}

class TrieNode {
    private TrieNode[] links;
    private int endsWith;
    private int prefixWith;

    public TrieNode() {
        this.links = new TrieNode[26];
        this.endsWith = 0;
        this.prefixWith = 0;
    }

    public boolean containsKey(char x) {
        return this.links[x - 'a'] != null;
    }

    public void putKey(char x) {
        this.links[x - 'a'] = new TrieNode();
    }

    public void removeKey(char x) {
        TrieNode node = this.links[x-'a'];
        node.decrementPrefixWith();
        return;
    }

    public void incrementEndsWith() {
        this.endsWith++;
    }

    public void decrementEndsWith() {
        this.endsWith--;
    }

    public void incrementPrefixWith() {
        this.prefixWith++;
    }

    public void decrementPrefixWith() {
        this.prefixWith--;
    }

    public TrieNode getKey(char x) {
        return this.links[x - 'a'];
    }

    public int getEndsWithCount() {
        return this.endsWith;
    }

    public int getPrefixWithCount() {
        return this.prefixWith;
    }
}
