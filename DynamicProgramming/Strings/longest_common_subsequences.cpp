#include <iostream>

using namespace std;

int lcs(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    int maxLen = 0;
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, s1, s2, dp);
    return dp[ind1][ind2] = max(lcs(ind1 - 1, ind2, s1, s2, dp), lcs(ind1, ind2 - 1, s1, s2, dp));
}

int lcsTabulation(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1, vector<int>(n2, 0));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (s1[i] == s2[j])
            {
                int prevLCS = (i - 1 >= 0 && j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                dp[i][j] = 1 + prevLCS;
            }
            else
            {
                int prevS1 = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int prevS2 = j - 1 >= 0 ? dp[i][j - 1] : 0;
                dp[i][j] = max(prevS1, prevS2);
            }
        }
    }

    // print LCS
    string lcs = "";
    int i = n1 - 1, j = n2 - 1;
    while (i >= 0 && j >= 0)
    {
        if (s1[i] == s2[j])
        {
            lcs += s1[i];
            i--, j--;
        }
        else
        {
            int lcsLeft = j - 1 >= 0 ? dp[i][j - 1] : 0;
            int lcsUp = i - 1 >= 0 ? dp[i - 1][j] : 0;
            if (lcsLeft < lcsUp)
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    return dp[n1 - 1][n2 - 1];
}