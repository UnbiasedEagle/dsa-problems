// Problem: Given a binary array containing 0’s and 1’s, find the largest subarray with equal numbers of 0’s and 1’s.

#include <bits/stdc++.h>
using namespace std;

vector<int> findLargestSubarrayWithEqual01a(vector<int> v)
{
    int maxLength = 0;
    int startIdx = -1;
    int endIdx = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int oneCount = 0;
        int zeroCount = 0;
        for (int j = i; j < v.size(); j++)
        {
            if (v[j] == 0)
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }

            if (oneCount == zeroCount)
            {
                if (j - i + 1 > maxLength)
                {
                    maxLength = j - i + 1;
                    startIdx = i;
                    endIdx = j;
                }
            }
        }
    }

    vector<int> ans;

    if (maxLength > 0)
    {
        for (int i = startIdx; i <= endIdx; i++)
        {
            ans.push_back(v[i]);
        }
    }

    return ans;
}

vector<int> findLargestSubarrayWithEqual01b(vector<int> v)
{
    // replace 0 with -1
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            v[i] = -1;
        }
    }

    // max subarray sum of zero
    unordered_map<int, int> mp;
    mp[0] = -1;
    int maxLength = 0;
    int startIdx = -1;
    int endIdx = -1;
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (mp.find(sum) != mp.end())
        {
            int start = mp[sum];
            if (i - start > maxLength)
            {
                maxLength = i - start;
                endIdx = i;
                startIdx = start + 1;
            }
        }

        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    vector<int> ans;
    if (maxLength > 0)
    {
        for (int i = startIdx; i <= endIdx; i++)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<int> ans = findLargestSubarrayWithEqual01a(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}