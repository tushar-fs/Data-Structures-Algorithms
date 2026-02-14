#include <iostream>

using namespace std;

bool checkIntersection(int a, int b, int c, int d)
{
    if (a > c)
    {
        swap(a, c);
        swap(b, d);
    }
    return c <= b;
}

int minMovesPiano(vector<int> &song)
{
    int n = song.size();
    int moves = 0;
    int thumb_min_pos = song[0] - 4;
    int thumb_max_pos = song[0];
    for (int i = 1; i < n; i++)
    {
        int new_thumb_min_pos = song[i] - 4;
        int new_thumb_max_pos = song[i];
        if (checkIntersection(thumb_min_pos, thumb_max_pos, new_thumb_min_pos, new_thumb_max_pos))
        {
            thumb_min_pos = max(thumb_min_pos, new_thumb_min_pos);
            thumb_max_pos = min(thumb_max_pos, new_thumb_max_pos);
        }
        else
        {
            moves++;
            thumb_max_pos = new_thumb_max_pos;
            thumb_min_pos = new_thumb_min_pos;
        }
    }
    return moves;
}

int main()
{
    vector<int> notes = {1, 5, 2, 6, 3, 7};
    cout << minMovesPiano(notes);
    return 0;
}