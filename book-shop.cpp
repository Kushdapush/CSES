#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if (price[i - 1] <= j)
            {
                pick += dp[i - 1][j - price[i - 1]] + pages[i - 1];
            }
            dp[i][j] = max(pick, notPick);
        }
    }

    cout << dp[n][x];
    return 0;
}