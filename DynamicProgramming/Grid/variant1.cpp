/**
 * Problem: Unique Paths (LC #62)
 * Count all paths from top-left to bottom-right of an m x n grid.
 * You can only move right or down. Solved with memoization and tabulation.
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m) — can be optimized to O(m)
 */
#include <iostream>
using namespace std;

// Memoization
int countAllPaths(int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int up = countAllPaths(n - 1, m, dp);
    int left = countAllPaths(n, m - 1, dp);
    return dp[n][m] = up + left;
}

// Tabulation
int countAllPathsTabulation(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int left = 0, down = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                if (i > 0)
                    down = dp[i - 1][j];
                dp[i][j] = left + down;
            }
        }
    }

    return dp[n - 1][m - 1];
}

// Space Optimisation
int countAllPathsTabulation(int n, int m)
{

    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                cur[j] = 1;
            else
            {
                int left = 0, top = 0;
                if (j > 0)
                    left = cur[j - 1];
                if (i > 0)
                    top = prev[j];
                cur[j] = left + top;
            }
        }
        prev = cur;
    }
    return prev[m - 1];
}