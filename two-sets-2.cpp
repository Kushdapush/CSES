#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;

    long long sum = 1LL * n * (n + 1) / 2;
    if(sum % 2 == 1) {
        cout << 0;
        return 0;
    }

    int target = sum / 2;
    vector<vector<long>> dp(n+1 , vector<long>(target+1 , 0));
    dp[0][0] = 1;

    for(int i=1 ; i<=n ; i++){
        for(int val = 0 ; val <= target ; val++){
            int notPick = dp[i-1][val];
            int pick = 0;
            if(i <= val){
                pick = dp[i-1][val-i];
            }
            dp[i][val] = (pick + notPick) % MOD;
        }
    }

    cout << (dp[n][target] * 500000004LL) % MOD;
    return 0;
}
