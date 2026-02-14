/**
 * Problem: Cherry Pickup II (LC #1463)
 * Collect maximum cherries using two robots (Alice & Bob). Alice starts at
 * (0, 0) and Bob starts at (0, col-1). Both move downward one row at a time,
 * choosing from 3 columns (left, stay, right). 3D DP on (row, aliceCol, bobCol).
 * Time Complexity: O(n * m²)
 * Space Complexity: O(n * m²)
 */
#include <iostream>

using namespace std;
const int MAX = 71;
int moves[] = {-1, 0, 1};
int dp[MAX][MAX][MAX];

bool isValidCol(int aliceCol, int bobCol, int m)
{
    return (aliceCol >= 0 && aliceCol < m && bobCol >= 0 && bobCol < m);
}

int getMaximumFruits(int row, int col1, int col2, vector<vector<int>> &grid)
{
    if (row == grid.size() - 1)
    {
        if (col1 == col2)
            return grid[row][col1];
        return grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    // move alice once and trace 3 corresponding moves of Bob
    int collectCurFruits = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);
    int allMaxi = -1e8;
    for (int i = 0; i < 3; i++)
    {
        int aliceCol = col1 + moves[i];
        for (int j = 0; j < 3; j++)
        {
            int bobCol = col2 + moves[j];
            if (isValidCol(aliceCol, bobCol, grid[0].size()))
                allMaxi = max(allMaxi, getMaximumFruits(row + 1, aliceCol, bobCol, grid));
        }
    }
    return dp[row][col1][col2] = allMaxi + collectCurFruits;
}

// Method2 -> Tabulation
int getMaximumFruitsTabulation(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int dp[71][71][71];
    memset(dp, -1, sizeof(dp));

    // base case when alice at (0,0) & bob at (0, m-1)
    dp[0][0][m - 1] = grid[0][0] + (0 != m - 1 ? grid[0][m - 1] : 0);

    for (int i = 1; i < n; i++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int cur = grid[i][j1];
                if (j2 != j1)
                    cur += grid[i][j2];
                // arrive from TOP
                int top = -1;
                if (j2 - 1 >= 0)
                    top = dp[i - 1][j1][j2 - 1];
                top = max(top, dp[i - 1][j1][j2]);
                if (j2 + 1 < m)
                    top = max(top, dp[i - 1][j1][j2 + 1]);

                // arrive from TOP_LEFT
                int topLeft = -1;
                if (j1 - 1 >= 0 && j2 - 1 >= 0)
                    topLeft = dp[i - 1][j1 - 1][j2 - 1];
                if (j1 - 1 >= 0)
                    topLeft = max(topLeft, dp[i - 1][j1 - 1][j2]);
                if (j1 - 1 >= 0 && j2 + 1 < m)
                    topLeft = max(topLeft, dp[i - 1][j1 - 1][j2 + 1]);

                // arrive from TOP_RIGHT
                int topRight = -1;
                if (j1 + 1 < m && j2 - 1 >= 0)
                    topRight = dp[i - 1][j1 + 1][j2 - 1];
                if (j1 + 1 < m)
                    topRight = max(topRight, dp[i - 1][j1 + 1][j2]);
                if (j1 + 1 < m && j2 + 1 < m)
                    topRight = max(topRight, dp[i - 1][j1 + 1][j2 + 1]);

                dp[i][j1][j2] = cur + max({top, topLeft, topRight});
            }
        }
    }

    int res = -1e9;
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            res = max(res, dp[n - 1][j1][j2]);
        }
    }
    return res;
}

int main()
{
    // 1. Initialize the DP table
    memset(dp, -1, sizeof(dp));

    // 2. Define a sample grid to test with
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}};

    // 3. Get dimensions and call the function
    int rows = grid.size();
    int cols = grid[0].size();
    int result = getMaximumFruits(0, 0, cols - 1, grid);

    // 4. Print the result
    cout << "Maximum fruits collected: " << result << endl;

    return 0;
}