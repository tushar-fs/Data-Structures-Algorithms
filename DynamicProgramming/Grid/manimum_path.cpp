/**
 * Problem: Minimum Path Sum (LC #64)
 * Given an m x n grid filled with non-negative numbers, find a path from
 * top-left to bottom-right that minimizes the sum of all numbers along the path.
 * You can only move right or down.
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 */
#include <iostream>

using namespace std;

int getMinimumPathSum(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return grid[n][m];
    if (n < 0 || m < 0)
        return INT_MAX;

    if (dp[n][m] != -1)
        return dp[n][m];

    int left = grid[n][m] + getMinimumPathSum(n, m - 1, grid, dp);
    int top = grid[n][m] + getMinimumPathSum(n - 1, m, grid, dp);
    return dp[n][m] = min(left, top);
}

// Tabulation
int getMinimumPathSumTabulation(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int left = INT_MAX, top = INT_MAX;
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                if (i > 0)
                    top = grid[i][j] + dp[i - 1][j];
                dp[i][j] = min(left, top);
            }
        }
    }
    return dp[n - 1][m - 1];
}