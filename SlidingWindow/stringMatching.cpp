/**
 * Problem: Permutation in String (LC #567)
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1.
 * Uses sliding window with frequency maps to check anagram substrings.
 * Time Complexity: O(n2 * 26)
 * Space Complexity: O(26) ≈ O(1)
 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool checkPermutation(string &s1, string &s2)
{
    unordered_map<char, int> freq1, freq2;
    int n1 = s1.size();
    int n2 = s2.size();

    for (char x : s1)
        freq1[x]++;

    int left = 0, right = 0;
    for (; right < n2; right++)
    {
        freq2[s2[right]]++;
        while (right - left + 1 > n1)
        {
            freq2[s2[left]]--;
            left++;
        }

        bool ok = true;
        for (auto x : freq1)
        {
            if (x.second != freq2[x.first])
            {
                ok = false;
            }
        }
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkPermutation(s1, s2);
    return 0;
}