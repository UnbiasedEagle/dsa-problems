// Problem: Given an integer array, print all subarrays with zero-sum.

#include <bits/stdc++.h>
using namespace std;

set<vector<int> > printAllSubarrayWithZeroSum1(vector<int> v)
{
    set<vector<int> > subarrays;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == 0)
            {
                vector<int> temp;
                for (int k = i; k <= j; k++)
                {
                    temp.push_back(v[k]);
                }
                subarrays.insert(temp);
            }
        }
    }
    return subarrays;
}

set<vector<int> > printAllSubarrayWithZeroSum2(vector<int> v)
{
    set<vector<int> > subarrays;

    unordered_multimap<int, int> mp;

    mp.insert({0, -1});
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (mp.find(sum) != mp.end())
        {
            auto it = mp.find(sum);
            while (it != mp.end() && it->first == sum)
            {
                int start = it->second + 1;
                int end = i;

                vector<int> temp;
                for (int k = start; k <= end; k++)
                {
                    temp.push_back(v[k]);
                }
                subarrays.insert(temp);
                it++;
            }
        }
        mp.insert({sum, i});
    }

    return subarrays;
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
    // set<vector<int> > ans = printAllSubarrayWithZeroSum1(v);
    set<vector<int> > ans = printAllSubarrayWithZeroSum2(v);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}