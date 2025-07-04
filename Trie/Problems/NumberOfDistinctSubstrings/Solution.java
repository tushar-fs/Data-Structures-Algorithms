package Trie.Problems.NumberOfDistinctSubstrings;

public class Solution {

    public int countDistinctSubstrings(String word) {
        TrieNode root = new TrieNode();
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            TrieNode node = root;
            for (int j = i; j < word.length(); j++) {
                char x = word.charAt(j);
                if (!node.containsKey(x)) {
                    node.putKey(x);
                    count++;
                }
                node = node.getKey(x);
            }
            node.setEnd();
        }
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
        return this.links[x - 'a'] != null;
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
}
