#include <iostream>

using namespace std;

bool isBuddy(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;

    int dist = s2[0] - s1[0];
    if (dist < 0)
        dist = (s2[0] - 'a') + ('z' - s1[0]) + 1;
    for (int i = 1; i < s1.size(); i++)
    {
        int curDist = s2[i] - s1[i];
        if (curDist < 0)
            curDist = (s2[i] - 'a') + ('z' - s1[i]) + 1;
        if (curDist != dist)
            return false;
    }
    return true;
}

void groupBuddies(vector<string> &words)
{
    int n = words.size();
    vector<bool> vis(n, false);
    vector<vector<string>> groups;
    for (int i = 0; i < n - 1; i++)
    {
        if (vis[i])
            continue;
        vector<string> curGroup = {words[i]};
        for (int j = i + 1; j < n; j++)
        {
            if (!vis[j] && isBuddy(words[i], words[j]))
            {
                curGroup.push_back(words[j]);
                vis[j] = true;
            }
        }
        groups.push_back(curGroup);
    }

    for (vector<string> vec : groups)
    {
        for (string word : vec)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}

string getSignature(string word)
{
    int offset = 26 - (word[0] - 'a');
    string str = "";
    str += "a";
    for (int i = 1; i < word.size(); i++)
    {
        str += (char)((word[i] + offset - 'a') % 26 + 'a');
    }
    return str;
}

void groupBuddiesOptimal(vector<string> words)
{
    int n = words.size();

    unordered_map<string, vector<string>> mpp;

    for (int i = 0; i < n; i++)
    {
        string sign = getSignature(words[i]);
        mpp[sign].push_back(words[i]);
    }
    for (auto x : mpp)
    {
        for (string s : x.second)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<string> words = {"abc", "bcd", "yza", "a", "z", "acef", "bdfg"};

    groupBuddiesOptimal(words);
    return 0;
}