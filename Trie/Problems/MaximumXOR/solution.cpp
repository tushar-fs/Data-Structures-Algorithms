#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
    TrieNode *links[2];

public:
    TrieNode()
    {
        for (int i = 0; i < 2; i++)
            links[i] = nullptr;
    }

    bool containsKey(int bit)
    {
        return this->links[bit];
    }

    void setKey(int bit)
    {
        this->links[bit] = new TrieNode();
    }

    TrieNode *getKey(int bit)
    {
        return this->links[bit];
    }
};

class TrieSolution
{
private:
    TrieNode *root;

public:
    TrieSolution()
    {
        this->root = new TrieNode();
    }

    void insert(int x)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int curBit = (x >> i) & 1;
            if (!node->containsKey(curBit))
            {
                node->setKey(curBit);
            }
            node = node->getKey(curBit);
        }
    }

    int getMaximumXor(int x)
    {
        TrieNode *node = root;
        int curMaxXOR = 0;
        for (int i = 31; i >= 0; i--)
        {
            int curBit = (x >> i) & 1;
            int oppositeBit = curBit ^ 1;
            if (node->containsKey(oppositeBit))
            {
                curMaxXOR = curMaxXOR | (1 << i);
                node = node->getKey(oppositeBit);
            }
            else
            {
                node = node->getKey(curBit);
            }
        }
        return curMaxXOR;
    }

    int findMaximumXOR(vector<int> &a1, vector<int> &a2)
    {

        // Creating Trie Tree for a1
        for (int x : a1)
        {
            this->insert(x);
        }

        // find element in a2 with maximum XOR in Trie
        int maxXor = 0;
        for (int i = 0; i < a2.size(); i++)
        {
            maxXor = max(maxXor, getMaximumXor(a2[i]));
        }
        return maxXor;
    }
};