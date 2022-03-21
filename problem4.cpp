// Problem: Given a binary array, sort it in linear time and constant space. The output should print all zeroes, followed by all ones.

#include <bits/stdc++.h>
using namespace std;

void sort01a(vector<int> &v)
{
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    int k = 0;
    for (int i = 0; i < zeroCount; i++)
    {
        v[k++] = 0;
    }

    for (int i = 0; i < oneCount; i++)
    {
        v[k++] = 1;
    }
}

void sort01b(vector<int> &v)
{
    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            v[k++] = 0;
        }
    }

    for (int i = k; i < v.size(); i++)
    {
        v[i] = 1;
    }
}

void sort01c(vector<int> &v)
{
    int swapIdx = 0;
    int pivotEl = 1;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            swap(v[i], v[swapIdx]);
            swapIdx++;
        }
    }
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

    // sort01a(v);
    sort01c(v);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}