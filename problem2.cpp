// Problem: Check if a subarray with 0 sum exists or not

#include <bits/stdc++.h>
using namespace std;

bool isSubarrayWithZeroSum1(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool isSubarrayWithZeroSum2(vector<int> v)
{
    unordered_set<int> s;
    s.insert(0);
    int sum = 0;
    for (auto i : v)
    {
        sum += i;
        if (s.find(sum) != s.end())
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
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
    // cout << isSubarrayWithZeroSum1(v);
    cout << isSubarrayWithZeroSum2(v);
    return 0;
}