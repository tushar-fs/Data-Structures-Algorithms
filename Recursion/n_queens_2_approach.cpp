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
    cout << "---------\n";
}

bool isSafe(int r, int c, int n, vector<vector<int>> &board)
{
    int i, j;

    // check in row
    for (int i = 0; i < c; i++)
    {
        if (board[r][i])
            return false;
    }

    // check in top left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // check in bottom left diagonal
    for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

void solve(int col, int n, vector<vector<int>> &board)
{
    if (col == n)
    {
        printQueens(n, board);
        return;
    }

    // Check for all row in a col
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, n, board))
        {
            board[i][col] = 1;
            solve(col + 1, n, board);
            board[i][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, n, board);
    return 0;
}