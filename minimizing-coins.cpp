#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
vector<int> coins;

/*
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
*/

int main() {
    int n, x;
    cin >> n >> x;

    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp.resize(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1 ; i<=x ; i++){
    	for(int j=0 ; j<n ; j++){
	    if(i >= coins[j]){
	    	dp[i] = min(dp[i], dp[i-coins[j]]+1);
	    }
	}
    }

    if (dp[x] >= 1e9) cout << -1 << "\n";
    else cout << dp[x] << "\n";
 
    return 0;
}

