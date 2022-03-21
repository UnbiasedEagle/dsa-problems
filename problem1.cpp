// Problem: Find a pair with the given sum in an array

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n2)
// Space Complexity: O(1)
pair<int, int> findPair1(vector<int> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            int sum = v[i] + v[j];

            if (sum == target)
            {
                return {v[i], v[j]};
            }
        }
    }

    return {-1, -1};
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
pair<int, int> findPair2(vector<int> v, int target)
{
    sort(v.begin(), v.end());
    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        int sum = v[start] + v[end];
        if (sum == target)
        {
            return {v[start], v[end]};
        }
        if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return {-1, -1};
}

pair<int, int> findPair3(vector<int> v, int target)
{
    unordered_set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        int comp = target - v[i];
        if (s.find(comp) != s.end())
        {
            return {v[i], comp};
        }
        s.insert(v[i]);
    }

    return {-1, -1};
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

    // pair<int, int> p = findPair1(v, target);
    // pair<int, int> p = findPair2(v, target);
    pair<int, int> p = findPair3(v, target);

    cout << p.first << " " << p.second << endl;

    return 0;
}