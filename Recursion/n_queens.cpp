/**
 * Problem: N-Queens (LC #51) — Approach 1
 * Place N queens on an N×N chessboard such that no two queens attack each other.
 * Uses backtracking with manual diagonal/column conflict checking.
 * Time Complexity: O(N!)
 * Space Complexity: O(N²)
 */
#include <iostream>
#include <vector>

using namespace std;

void printQueens(int n, vector<vector<int>> &mat)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j])
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

bool checkSafe(int r, int c, vector<vector<int>> &vis)
{
}

void solve(int n, int &placedQueen, vector<vector<int>> &vis)
{
    if (placedQueen == n)
    {
        printQueens(n, vis);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (checkSafe(i, j, vis))
            {
                placedQueen++;
                vis[i][j] = 1;
                solve(n, placedQueen, vis);
                vis[i][j] = 0;
                placedQueen--;
            }
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int placedQueen = 0;
    solve(n, placedQueen, vis);
    return 0;
}