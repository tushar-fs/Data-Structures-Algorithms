#include "../mybits/stdc++.h"
using namespace std;

class TrieNode
{
public:
    TrieNode *links[26];
    bool flag;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
        flag = false;
    }

    bool containsKey(char x)
    {
        return links[x - 'a'] != nullptr;
    }

    void putKey(char x)
    {
        links[x - 'a'] = new TrieNode();
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char x : word)
        {
            if (!node->containsKey(x))
            {
                node->putKey(x);
            }
            node = node->links[x - 'a'];
        }
        node->flag = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char &x : word)
        {
            if (!node->containsKey(x))
                return false;
            node = node->links[x - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char &x : prefix)
        {
            if (!node->containsKey(x))
                return false;
            node = node->links[x - 'a'];
        }
        return true;
    }
};

int main()
{
    string words[] = {"apple", "apps", "apxl", "bac", "bat"};
    Trie dict;
    for (string word : words)
    {
        dict.insert(word);
    }

    return 0;
}