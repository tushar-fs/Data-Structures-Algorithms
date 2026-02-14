/**
 * Problem: Unique Paths II — With Obstacles (LC #63)
 * Count all paths from top-left to bottom-right with obstacles in the grid.
 * Cells with -1 are blocked. You can only move right or down.
 * Solved with memoization and tabulation.
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 */
#include <iostream>
using namespace std;

// Memoization
int countAllPaths(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0 || grid[n][m] == -1)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int up = countAllPaths(n - 1, m, grid, dp);
    int left = countAllPaths(n, m - 1, grid, dp);
    return dp[n][m] = up + left;
}

// Tabulation
int countAllPathsTabulation(int n, int m, vector<vector<int>> &mat)
{
    // cell with -1 is obstacle
    if (mat[0][0] == -1)
        return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int top = 0, left = 0;
                if (i > 0)
                    top = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = top + left;
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