// Problem: Given two sorted arrays, X[] and Y[] of size m and n each, merge elements of X[] with elements of array Y[] by maintaining the sorted order, i.e., fill X[] with the first m smallest elements and fill Y[] with remaining elements.

#include <bits/stdc++.h>
using namespace std;

void merge1(vector<int> &x, vector<int> &y)
{
    int i = 0;
    int j = 0;

    vector<int> ans1(x.size());
    vector<int> ans2(y.size());

    int a = 0;
    int b = 0;

    while (i < x.size() && j < y.size())
    {
        if (x[i] < y[j])
        {
            if (a < x.size())
            {
                ans1[a] = x[i];
                a++;
            }
            else
            {
                ans2[b] = x[i];
                b++;
            }
            i++;
        }
        else
        {
            if (a < x.size())
            {
                ans1[a] = y[j];
                a++;
            }
            else
            {
                ans2[b] = y[j];
                b++;
            }
            j++;
        }
    }

    while (i < x.size())
    {
        if (a < x.size())
        {
            ans1[a] = x[i];
            a++;
        }
        else
        {
            ans2[b] = x[i];
            b++;
        }
        i++;
    }

    while (j < y.size())
    {
        if (a < x.size())
        {
            ans1[a] = y[j];
            a++;
        }
        else
        {
            ans2[b] = y[j];
            b++;
        }
        j++;
    }

    x = ans1;
    y = ans2;
}

void merge2(vector<int> &x, vector<int> &y)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (y[0] < x[i])
        {
            swap(x[i], y[0]);
            int j = 0;
            while (y[j] > y[j + 1] && j + 1 < y.size())
            {
                swap(y[j], y[j + 1]);
                j++;
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> x(m);
    vector<int> y(n);

    for (auto &i : x)
    {
        cin >> i;
    }

    for (auto &i : y)
    {
        cin >> i;
    }

    // merge1(x, y);
    merge2(x, y);

    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : y)
    {
        cout << i << " ";
    }

    return 0;
}