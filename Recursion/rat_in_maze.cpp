/**
 * Problem: Rat in a Maze
 * Given an n x m maze, find all paths from top-left (0,0) to bottom-right
 * (n-1, m-1). The rat can move in 4 directions (D, L, R, U).
 * Prints all valid paths using backtracking.
 * Time Complexity: O(4^(n*m))
 * Space Complexity: O(n * m) — visited matrix + recursion
 */
#include <iostream>

using namespace std;

void ratInAMaze(int i, int j, string &path, vector<vector<int>> &mat, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        for (char x : path)
        {
            cout << x;
        }
        cout << "\n";
        return;
    }

    // move up
    if (i - 1 >= 0 && mat[i - 1][j] == 1)
    {
        path += "U";
        ratInAMaze(i - 1, j, path, mat, n, m);
        path.pop_back();
    }

    // move right
    if (j + 1 < m && mat[i][j + 1] == 1)
    {
        path += "R";
        ratInAMaze(i, j + 1, path, mat, n, m);
        path.pop_back();
    }

    // move down
    if (i + 1 < n && mat[i + 1][j] == 1)
    {
        path += "D";
        ratInAMaze(i + 1, j, path, mat, n, m);
        path.pop_back();
    }

    // move left
    if (j - 1 >= 0 && mat[i][j - 1] == 1)
    {
        path += "L";
        ratInAMaze(i, j - 1, path, mat, n, m);
        path.pop_back();
    }
}

int main()
{

    return 0;
}