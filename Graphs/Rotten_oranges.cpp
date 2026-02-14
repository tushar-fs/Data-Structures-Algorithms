/**
 * Problem: Rotting Oranges (LC #994)
 * Given a grid where 2 = rotten orange, 1 = fresh orange, 0 = empty cell,
 * find the minimum time for all oranges to rot. Uses multi-source BFS.
 * Return -1 if not all oranges can rot.
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 */
#include <iostream>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int orangesRotten(vector<vector<int>> &grid)
{
    // 2 -> rotten cell
    // 1 -> fresh orange cell
    // 0 -> empty cell

    int n = grid.size();
    int m = grid[0].size();
    int minTime = 0, freshCount = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }

    if (freshCount == 0)
        return 0;

    auto isSafe = [n, m](int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    while (!q.empty())
    {
        int sz = q.size();
        minTime++;
        for (int i = 0; i < sz; i++)
        {
            auto [r, c] = q.front();

            q.pop();
            // rot all 4 directions
            for (int d = 0; d < 4; d++)
            {
                int newi = r + dx[d];
                int newj = c + dy[d];
                if (isSafe(newi, newj) && grid[newi][newj] == 1)
                {
                    grid[newi][newj] = 2;
                    q.push({newi, newj});
                    freshCount--;
                }
            }
        }
    }
    if (freshCount != 0)
        return -1;
    return minTime - 1;
}