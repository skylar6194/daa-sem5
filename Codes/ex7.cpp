#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> weights, vector<int> values, int capacity)
{
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Knapsack Table:" << endl;
    cout << "  | ";
    for (int w = 0; w <= capacity; w++)
    {
        cout << w << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            cout << "  | ";
        }
        else
        {
            cout << "Item " << i << " | ";
        }
        for (int w = 0; w <= capacity; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    return dp[n][capacity];
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int max_value = knapsack(weights, values, capacity);
    cout << "Maximum value that can be put in a knapsack of capacity " << capacity << " is " << max_value << endl;

    return 0;
}