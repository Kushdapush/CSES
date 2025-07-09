#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int N = 1000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<long>> dp(N+1 , vector<long>(2,0));
	
    dp[1][0] = 1;
    dp[1][1] = 1;
	
    for(int i=2 ; i<=N ; i++){
	dp[i][0] = (dp[i-1][1] + 4*dp[i-1][0])%mod;
	dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%mod;
    }

    int t;
    cin >> t;

    while(t--){
    	int n;
	cin >> n;
	cout << (dp[n][0] + dp[n][1])%mod << "\n";
    }
}