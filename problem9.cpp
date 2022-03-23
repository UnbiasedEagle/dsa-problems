// Problem: Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.

#include <bits/stdc++.h>
using namespace std;

void sort012a(vector<int> &nums)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    for (auto i : nums)
    {
        if (i == 0)
        {
            zeroCount++;
        }
        else if (i == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
    }

    int k = 0;
    for (int i = 0; i < zeroCount; i++)
    {
        nums[k++] = 0;
    }
    for (int i = 0; i < oneCount; i++)
    {
        nums[k++] = 1;
    }

    for (int i = 0; i < twoCount; i++)
    {
        nums[k++] = 2;
    }
}

void sort012b(vector<int> &nums)
{
    int i = 0;
    int swapIdx = 0;
    int end = nums.size() - 1;

    while (i <= end)
    {
        if (nums[i] == 1)
        {
            i++;
        }
        else if (nums[i] == 0)
        {
            swap(nums[i], nums[swapIdx]);
            swapIdx++;
            i++;
        }
        else
        {
            swap(nums[i], nums[end]);
            end--;
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
    // sort012a(v);
    sort012b(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}