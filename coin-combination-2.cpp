#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int &i : c) cin >> i;
    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for(int i=0 ; i<n ; i++) dp[i][0] = 1;
    
    for(int i = n-1 ; i>=0 ; i--){
    	for(int sum = 1 ; sum <= x ; sum++){
    	    int notPick = dp[i+1][sum];
    	    int pick = 0;
    	    if(c[i] <= sum){
    	    	pick = dp[i][sum-c[i]];
     	    }
    	    dp[i][sum] = (pick + notPick)%mod;
    	}
    }

    cout << dp[0][x];

    return 0;
}
