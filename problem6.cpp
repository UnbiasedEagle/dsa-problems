// Problem: Given an integer array, find the largest subarray formed by consecutive integers. The subarray should contain all distinct values.

#include <bits/stdc++.h>
using namespace std;

bool isConsecutive(vector<int> v, int start, int end, int minElement, int maxElement)
{
    if (end - start != maxElement - minElement)
    {
        return false;
    }

    unordered_set<int> s;

    for (int i = start; i <= end; i++)
    {
        if (s.find(v[i]) != s.end())
        {
            return false;
        }
        s.insert(v[i]);
    }

    for (int i = minElement; i <= maxElement; i++)
    {
        if (s.find(i) == s.end())
        {
            return false;
        }
    }

    return true;
}

pair<int, int> maxConsecutiveInteger(vector<int> v)
{
    if (v.size() == 0)
    {
        return {-1, -1};
    }
    int maxLength = 1;
    int lastIndex = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int minElement = v[i];
        int maxElement = v[i];
        for (int j = i; j < v.size(); j++)
        {
            minElement = min(minElement, v[j]);
            maxElement = max(maxElement, v[j]);

            if (isConsecutive(v, i, j, minElement, maxElement))
            {
                if (j - i + 1 > maxLength)
                {
                    maxLength = j - i + 1;
                    lastIndex = j;
                }
            }
        }
    }

    return {maxLength, lastIndex};
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
    pair<int, int> ans = maxConsecutiveInteger(v);

    if (ans.first == -1)
    {
        cout << "No such subarray";
    }
    else
    {
        cout << "Subarray of length: " << ans.first << endl;
        cout << "Starting: " << (ans.second - ans.first + 1) << " Ending: " << ans.second;
    }
    return 0;
}