package Trie.Problems.LongestWordWithAllPrefixes;

import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    private TrieNode root;
    private String longestWord;

    public Solution() {
        this.root = new TrieNode();
        this.longestWord = "";
    }

    public void insert(String word) {
        TrieNode node = root;
        boolean allPrefixExists = true;
        for(int i=0;i<word.length();i++) {
            char x = word.charAt(i);
            if(!node.containsKey(x)) {
                node.putKey(x);
            }
            node = node.getKey(x);
            if(i<word.length()-1) {
                allPrefixExists = allPrefixExists && node.getFlag();
            }
        }
        node.setFlag();
        if(allPrefixExists) {
            if(word.length() > this.longestWord.length()) {
                this.longestWord = word;
            }
        }
    }

    public String getLongestWord() {
        return this.longestWord;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0;i<n;i++) {
            String s = sc.next();
            words[i] = s;
        }
        sc.close();
        Arrays.sort(words);
        Solution trieSol = new Solution();
        for(String s: words) {
            trieSol.insert(s);
        }

        System.out.println("Longest word with all prefix is: " + trieSol.getLongestWord());
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
        return this.links[x-'a'] != null;
    }

    public void putKey(char x) {
        this.links[x-'a'] = new TrieNode();
    }

    public TrieNode getKey(char x) {
        return this.links[x-'a'];
    }

    public void setFlag() {
        this.flag = true;
    }

    public boolean getFlag() {
        return this.flag;
    }

}
