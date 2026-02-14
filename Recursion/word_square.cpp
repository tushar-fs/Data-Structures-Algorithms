/**
 * Problem: Word Squares (LC #425)
 * Given a set of words, find all word squares you can build from them.
 * A word square is a sequence of words where the kth row and kth column
 * read the same string. Uses Trie for efficient prefix lookup + backtracking.
 * Time Complexity: O(n * 26^L) where L = word length
 * Space Complexity: O(n * L)
 */
#include <iostream>
#include <memory>

using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    bool isEndOfWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

struct Trie
{
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }
    ~Trie()
    {
        delete root;
    }

    void getWordsWithPrefixHelper(TrieNode *curNode, string &curPrefix, vector<string> &words)
    {
        if (curNode->isEndOfWord)
        {
            words.push_back(curPrefix);
        }
        for (int i = 0; i < 26; i++)
        {
            if (curNode->links[i] != nullptr)
            {
                curPrefix += (char)(i + 'a');
                getWordsWithPrefixHelper(curNode->links[i], curPrefix, words);
                curPrefix.pop_back();
            }
        }
    }

    vector<string> getWordsWithPrefix(const string &prefix)
    {
        TrieNode *curNode = root;
        for (char ch : prefix)
        {
            if (curNode->links[ch - 'a'] != nullptr)
            {
                curNode = curNode->links[ch - 'a'];
            }
            else
                return {};
        }

        if (curNode == nullptr)
            return {};
        vector<string> words;
        string curPrefix = prefix;
        getWordsWithPrefixHelper(curNode, curPrefix, words);
        return words;
    }

    void insertWord(string &word)
    {
        TrieNode *curNode = root;
        for (char c : word)
        {
            if (curNode->links[c - 'a'] == nullptr)
            {
                curNode->links[c - 'a'] = new TrieNode();
            }
            curNode = curNode->links[c - 'a'];
        }
        curNode->isEndOfWord = true;
    }
};

void solve(int ind, vector<string> &container, int k, vector<vector<string>> &allLists, Trie *prefixTree)
{
    if (ind == k)
    {
        allLists.push_back(container);
        return;
    }

    string prefixWord = "";
    for (string &s : container)
    {
        prefixWord += s[ind];
    }

    vector<string> words = prefixTree->getWordsWithPrefix(prefixWord);

    for (string &word : words)
    {
        container.push_back(word);
        solve(ind + 1, container, k, allLists, prefixTree);
        container.pop_back();
    }
}

int main()
{
    vector<string> wordList{"abat", "baba", "atan", "atal"};
    Trie prefixTree;
    for (string word : wordList)
    {
        prefixTree.insertWord(word);
    }
    vector<vector<string>> allLists;
    vector<string> container;
    solve(0, container, wordList[0].size(), allLists, &prefixTree);
    for (auto it : allLists)
    {
        for (string s : it)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}