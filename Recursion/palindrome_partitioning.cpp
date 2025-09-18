#include <iostream>

using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    if (i >= j)
        return true;

    return (s[i] == s[j]) && isPalindrome(i + 1, j - 1, s);
}

void solve(int ind, string &s, vector<string> &container, vector<vector<string>> &res)
{
    if (ind == s.size())
    {
        res.push_back(container);
        return;
    }

    string subStr = "";
    for (int i = ind; i < s.size(); i++)
    {
        subStr += s[i];
        if (isPalindrome(0, subStr.size() - 1, subStr))
        {
            container.push_back(subStr);
            solve(i + 1, s, container, res);
            container.pop_back();
        }
    }
}

int main()
{
    string s = "aab";
    vector<string> container;
    vector<vector<string>> res;
    solve(0, s, container, res);
    for (auto v : res)
    {
        for (auto p : v)
        {
            cout << p << " ";
        }
        cout << "\n";
    }
    return 0;
}