/*
To determine if there exists a subset within a given set
of integers that sums up to specified target value.
It does by generating possible subsets, calculating their sums,
and checking if any subset matches target su
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if a subset with a given sum exists
int subsetSum(int arr[], int n, int totalsum)
{
    for (int r = 1; r < (1 << n); ++r)
    {
        int subset_sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (r & (1 << i))
            {
                subset_sum += arr[i];
            }
        }
        if (subset_sum == totalsum)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int value;
    cout << "Enter the target sum: ";
    cin >> value;

    if (subsetSum(arr, n, value))
    {
        cout << "Found a subset with sum " << value << endl;
    }
    else
    {
        cout << "No subset with sum " << value << " exists" << endl;
    }
    return 0;
}