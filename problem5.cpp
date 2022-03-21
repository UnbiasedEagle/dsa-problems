// Problem: Given a limited range array of size n containing elements between 1 and n-1 with one element repeating, find the duplicate number in it without using any extra space.

#include <bits/stdc++.h>
using namespace std;

int findDuplicate1(vector<int> v)
{
    unordered_set<int> s;
    for (auto i : v)
    {
        if (s.find(i) != s.end())
        {
            return i;
        }
        s.insert(i);
    }

    return -1;
}

int findDuplicate2(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int val = abs(v[i]);
        if (v[val] > 0)
        {
            v[val] = -1 * v[val];
        }
        else
        {
            return val;
        }
    }

    return -1;
}

int findDuplicate3(vector<int> v)
{
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

    cout << findDuplicate3(v);
    return 0;
}