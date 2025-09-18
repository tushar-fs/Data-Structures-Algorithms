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