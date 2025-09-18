#include "mybits/stdc++.h"

using namespace std;

int getMaximumAppearingElement(vector<int> &left, vector<int> &right)
{
    vector<int> freq(10001, 0);
    int n = left.size();
    for (int i = 0; i < n; i++)
    {
        freq[left[i]]++;
        freq[right[i] + 1]--;
    }
}

int main()
{
    vector<int> left = {1, 2, 5, 15};
    vector<int> right = {5, 8, 7, 18};

    return 0;
}