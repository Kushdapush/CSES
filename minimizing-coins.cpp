#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
vector<int> coins;

long long func(int i, int x) {
    if (i == 0) {
        if (x % coins[0] == 0) return x / coins[0];
        return 1e9;  // INF
    }

    if (dp[i][x] != -1) return dp[i][x];

    long long not_pick = func(i - 1, x);
    long long pick = 1e9;
    if (coins[i] <= x) {
        pick = 1 + func(i, x - coins[i]);
    }

    return dp[i][x] = min(pick, not_pick);
}

int main() {
    int n, x;
    cin >> n >> x;

    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp.resize(n, vector<long long>(x + 1, -1));

    long long ans = func(n - 1, x);
    if (ans >= 1e9) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}

