#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int &i : c) cin >> i;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <=x; i++) {
        for (int j = 0; j < n; j++) {
            if(c[j] <= i) dp[i] = (dp[i-c[j]] + dp[i]) % mod;
        }
    }
    cout << dp[x];

    return 0;
}
