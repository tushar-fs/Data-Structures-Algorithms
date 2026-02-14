/**
 * Problem: Maximum Earning
 * Given a binary string representing work days (1) and off days (0), a fixed
 * daily pay, a bonus for consecutive work days, and K optional extra work days,
 * maximize total earnings by strategically choosing which off days to work.
 * Time Complexity: O(n * k)
 * Space Complexity: O(n)
 */
#include <iostream>

using namespace std;

int getMaximumEarning(string &s, int k, int fixedPay, int bonus)
{
    int days = s.size(), freeDay = 0;
    int totalEarning = s[0] == '1' ? fixedPay : 0;
    vector<int> one_indexes;
    for (int i = 1; i < days; i++)
    {
        if (s[i] == '1')
        {
            totalEarning += fixedPay;
            if (s[i] == s[i - 1])
                totalEarning += bonus;
            one_indexes.push_back(i);
        }
    }

    vector<int> typeAGap, typeBGap, typeCGap;

    for (int i = 0; i < days; i++)
    {
        if (s[i] == '0')
        {
            int start = i;
            while (i + 1 < days && s[i + 1] == '0')
            {
                i++;
            }
            int end = i;
            int gap_len = end - start + 1;

            int left_one_exists = (start > 0 && s[start - 1] == '1');
            int right_one_exists = (end + 1 < days && s[end + 1] == '1');

            if (left_one_exists && right_one_exists)
            {
                typeAGap.push_back(gap_len);
            }
            else if (left_one_exists || right_one_exists)
            {
                typeBGap.push_back(gap_len);
            }
            else
            {
                typeCGap.push_back(gap_len);
            }
        }
    }

    // Greedily fill smaller gaps first to get maximum bonus in earnings
    sort(typeAGap.begin(), typeAGap.end());

    for (int len : typeAGap)
    {
        int useSlots = min(k, len);
        totalEarning += (useSlots * fixedPay) + ((useSlots + 1) * bonus);
        k -= useSlots;
        if (k == 0)
            break;
    }

    if (k > 0)
    {
        // use TypeB slots
        for (int len : typeBGap)
        {
            int useSlots = min(k, len);
            totalEarning += (useSlots * fixedPay) + (useSlots * bonus);
            k -= useSlots;
            if (k == 0)
                break;
        }
    }

    if (k > 0)
    {
        // use TypeC slots
        for (int len : typeCGap)
        {
            int useSlots = min(k, len);
            totalEarning += (useSlots * fixedPay) + ((useSlots - 1) * bonus);
            k -= useSlots;
            if (k == 0)
                break;
        }
    }

    return totalEarning;
}

int main()
{
    string s;
    cin >> s;
    int k, fixedPay, bonus;
    cin >> k >> fixedPay >> bonus;
    cout << getMaximumEarning(s, k, fixedPay, bonus);
}

/**
 *
 * 01001010, k = 2
 */