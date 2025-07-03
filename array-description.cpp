#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n , m;
  cin >> n >> m;
  
  vector<int> value(n);
  for(int i=0 ; i<n ; i++) cin >> value[i];
  
  vector<vector<long>> dp(n+1 , vector<long>(m+2 , 0));
  
  if(value[0] == 0){
    for(int i=1 ; i<=m ; i++) dp[0][i] = 1;
  } else {
      dp[0][value[0]] = 1;
  }
  
  for (int i = 1; i < n; i++) {
        if (value[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (
                    (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD + dp[i - 1][j + 1]
                ) % MOD;
            }
        } else {
            int j = value[i];
            dp[i][j] = (
                (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD + dp[i - 1][j + 1]
            ) % MOD;
        }
    }
  
  long ans = 0;
    for(int i=1 ; i<=m ; i++){
      ans = (ans + dp[n-1][i])%MOD;
    }
    
    cout << ans << endl;
  
  return 0;
}
