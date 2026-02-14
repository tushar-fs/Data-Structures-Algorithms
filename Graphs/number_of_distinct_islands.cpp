/**
 * Problem: Number of Distinct Islands (LC #694)
 * Given a 2D grid, count the number of distinct islands. Two islands are
 * considered the same if they have the same shape (translation, not rotation).
 * Uses DFS + relative coordinate hashing to identify unique shapes.
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 */
#include <iostream>
#include <set>

using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

bool isSafe(int i, int j, vector<vector<int>> &grid)
{
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

void dfs(pair<int, int> node, vector<vector<bool>> &vis, vector<vector<int>> &grid, pair<int, int> &basePoint, vector<pair<int, int>> &curIsland)
{
    auto [x, y] = node;
    vis[x][y] = true;
    auto [sourceX, sourceY] = basePoint;
    curIsland.push_back({x - sourceX, y - sourceY});
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (isSafe(newx, newy, grid) && !vis[newx][newy] && grid[newx][newy] == 1)
        {
            dfs({newx, newy}, vis, grid, basePoint, curIsland);
        }
    }
}

int getNumberOfDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    set<vector<pair<int, int>>> uniqueIslands;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> curIsland;
                pair<int, int> basePoint = {i, j};
                dfs({i, j}, vis, grid, basePoint, curIsland);
                sort(curIsland.begin(), curIsland.end()); // considering only canonical structure
                uniqueIslands.insert(curIsland);
            }
        }
    }

    return uniqueIslands.size();
}