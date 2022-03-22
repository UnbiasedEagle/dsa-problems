// Problem: Given an integer array, find the maximum length subarray having a given sum.

#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxLenSubarray1(vector<int> v, int target)
{
    int startIdx = -1;
    int endIdx = -1;
    int maxLength = 0;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == target)
            {
                if (j - i + 1 > maxLength)
                {
                    startIdx = i;
                    endIdx = j;
                    maxLength = j - i + 1;
                }
            }
        }
    }

    if (maxLength > 0)
    {
        for (int i = startIdx; i <= endIdx; i++)
        {
            ans.push_back(v[i]);
        }
    }

    return ans;
}

vector<int> findMaxLenSubarray2(vector<int> v, int target)
{
    unordered_map<int, int> map;

    map[0] = -1;

    int maxLength = 0;
    int startIdx = -1;
    int endIdx = -1;

    vector<int> ans;
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];

        int comp = sum - target;

        if (map.find(comp) != map.end())
        {
            if (i - map[comp] + 1 > maxLength)
            {
                maxLength = i - map[comp] + 1;
                startIdx = map[comp] + 1;
                endIdx = i;
            }
        }

        if (map.find(sum) == map.end())
        {
            map[sum] = i;
        }
    }

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
    int target;
    cin >> target;

    vector<int> ans = findMaxLenSubarray2(v, target);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}