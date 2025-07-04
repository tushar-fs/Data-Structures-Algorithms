package Trie.TrieImpl1;

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
        }
        node.setEnd();
    }

    public TrieNode findNode(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char x = word.charAt(i);
            if (!node.containsKey(x))
                return null;
            node = node.getKey(x);
        }
        return node;
    }

    public boolean search(String word) {
        TrieNode node = findNode(word);
        return node != null && node.getFlag();
    }

    public boolean startsWith(String prefix) {
        TrieNode node = findNode(prefix);
        return node != null;
    }

    public int countWordsEqualTo(String word) {
        int count = 0;
        
        return count;
    }
}

class TrieNode {
    private TrieNode[] links;
    private boolean flag;

    public TrieNode() {
        this.links = new TrieNode[26];
        this.flag = false;
    }

    public boolean containsKey(char x) {
        if (this.links[x - 'a'] != null)
            return true;
        return false;
    }

    public void putKey(char x) {
        this.links[x - 'a'] = new TrieNode();
    }

    public TrieNode getKey(char x) {
        return this.links[x - 'a'];
    }

    public void setEnd() {
        this.flag = true;
    }

    public boolean getFlag() {
        return this.flag;
    }
}
