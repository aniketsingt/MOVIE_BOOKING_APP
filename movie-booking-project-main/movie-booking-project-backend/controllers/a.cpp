#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<int> max_profits;
vector<bool> selling(1, true);

int sell(int a, int b = 0)
{
    selling[0] = false;
    return a + b;
}

int buy(int a, int b = 0)
{
    selling[0] = true;
    return a - b;
}

void dp(int profit, int i, vector<int> &arr)
{
    if (profit < 0)
        return;
    if (i >= arr.size())
    {
        max_profits.insert(profit);
        return;
    }

    if (selling[0])
    {
        dp(sell(profit, arr[i]), i + 1, arr);
        dp(buy(profit), i + 1, arr);
    }
    else
    {
        dp(buy(profit, arr[i]), i + 1, arr);
        dp(sell(profit), i + 1, arr);
    }
}

int histMaxProfit(vector<int> &arr)
{
    dp(0, 0, arr);
    return *max_element(max_profits.begin(), max_profits.end()) % 1000000000;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 2, 1, 5};
    cout << histMaxProfit(arr) << endl;
    return 0;
}