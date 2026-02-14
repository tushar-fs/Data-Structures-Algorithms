#include <iostream>

using namespace std;

// find minimum path sum in a triangular grid

int getMinPathSum(int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
        }
        dp[i][i] = grid[i][i] + dp[i - 1][i - 1];
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}

// space optimisation
int getMinPathSum(int n, vector<vector<int>> &grid)
{

    vector<int> prevRow(n, INT_MAX);
    prevRow[0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        vector<int> curRow(n, INT_MAX);
        curRow[0] = prevRow[0] + grid[i][0];
        for (int j = 1; j < i; j++)
        {
            curRow[j] = grid[i][j] + min(prevRow[j], prevRow[j - 1]);
        }
        curRow[i] = grid[i][i] + prevRow[i - 1];
        prevRow = curRow;
    }

    return *min_element(prevRow.begin(), prevRow.end());
}
