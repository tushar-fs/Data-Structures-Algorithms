#include <iostream>
#include "../mybits/stdc++.h"

using namespace std;

/**
 * Time Complexity: O(b*b*r)
 */

int findBestApartment(vector<unordered_map<string, bool>> &blocks, vector<string> &requirements)
{
    int n = blocks.size();

    int bestApt = -1;
    int maxClosestDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int farthestReqDist = 0;
        for (string req : requirements)
        {
            int minReqDist = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (blocks[j][req])
                {
                    minReqDist = min(minReqDist, abs(j - i));
                }
            }
            farthestReqDist = max(farthestReqDist, minReqDist);
        }
        if (maxClosestDist > farthestReqDist)
        {
            bestApt = i;
            maxClosestDist = farthestReqDist;
        }
    }
    return bestApt;
}

/**
 * Time Complexity: O(b*r)
 */

int efficientlyFindBestApartment(vector<unordered_map<string, bool>> &blocks, vector<string> &requirements)
{
    int n = blocks.size();
    int bestApt = -1;
    unordered_map<int, unordered_map<string, int>> closestAmenityDist;
    for (string req : requirements)
    {
        int lastSeen = -n;
        for (int i = 0; i < n; i++)
        {
            if (blocks[i][req])
            {
                lastSeen = i;
            }
            closestAmenityDist[i][req] = i - lastSeen;
        }

        lastSeen = 2 * n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (blocks[i][req])
            {
                lastSeen = i;
            }
            closestAmenityDist[i][req] = min(closestAmenityDist[i][req], lastSeen - i);
        }
    }

    int minFarthestDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int maxmDistCurBlock = 0;
        for (string req : requirements)
        {
            maxmDistCurBlock = max(maxmDistCurBlock, closestAmenityDist[i][req]);
        }
        if (maxmDistCurBlock < minFarthestDist)
        {
            bestApt = i;
            minFarthestDist = maxmDistCurBlock;
        }
    }
    return bestApt;
}

int main()
{
    // A list of apartment blocks, where each block has a set of amenities.
    vector<unordered_map<string, bool>> blocks = {
        {{"gym", true}, {"school", false}, {"store", false}, {"park", false}},                  // 0
        {{"gym", false}, {"school", true}, {"store", false}, {"park", false}},                  // 1
        {{"gym", false}, {"school", false}, {"store", false}, {"park", true}},                  // 2
        {{"gym", false}, {"school", false}, {"store", true}, {"park", false}},                  // 3
        {{"gym", false}, {"school", true}, {"store", true}, {"park", false}},                   // 4
        {{"gym", false}, {"school", false}, {"store", false}, {"park", false}},                 // 5 (Empty block)
        {{"gym", false}, {"school", false}, {"store", false}, {"park", false}, {"pool", true}}, // 6
        {{"gym", true}, {"school", false}, {"store", false}, {"park", false}}                   // 7
    };

    // A list of your required amenities.
    // Notice "school" and "pool" are not required.
    vector<string> requirements = {"gym", "store", "park"};

    // You can now pass 'blocks' and 'requirements' to your function
    // that solves the apartment hunting problem.

    // For example:
    int optimalBlockIndex = findBestApartment(blocks, requirements);
    cout << "The best block to live in is at index: " << optimalBlockIndex << endl;

    return 0;
}