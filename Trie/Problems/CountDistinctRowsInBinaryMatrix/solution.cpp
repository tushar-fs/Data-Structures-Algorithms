#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
private:
    TrieNode *links[2];
    bool flag;

public:
    TrieNode()
    {
        for (int i = 0; i < 2; i++)
        {
            this->links[i] = nullptr;
        }
        flag = false;
    }

    bool containsKey(int bit)
    {
        return this->links[bit];
    }

    void putKey(int bit)
    {
        this->links[bit] = new TrieNode();
    }

    TrieNode *getKey(int bit)
    {
        return this->links[bit];
    }

    bool getFlag()
    {
        return this->flag;
    }

    void setFlag()
    {
        this->flag = true;
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

    bool insert(vector<int> &arr)
    {
        TrieNode *node = root;
        for (int x : arr)
        {
            if (!node->containsKey(x))
            {
                node->putKey(x);
            }
            node = node->getKey(x);
        }
        if (!node->getFlag())
        {
            node->setFlag();
            return true;
        }
        return false;
    }

    int getDistinctRows(vector<vector<int>> &mat)
    {
        int count = 0;
        for (vector<int> &arr : mat)
        {
            count += insert(arr);
        }
        return count;
    }
};