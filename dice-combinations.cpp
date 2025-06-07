#include<bits/stdc++.h>
using namespace std;

vector<long long> dp;
const int MOD = 1e9 + 7;

long long func(int n){
  if(n == 0) return 1;
  if(n < 0 ) return 0;
  
  if(dp[n] != -1) return dp[n];
  
  long long res = 0;
  for(int i=1 ; i<=6 ; i++){
    res = (res + func(n - i)) % MOD;
  }
  
  return dp[n] = res;
}

int main(){
  int n;
  cin >> n;
  dp.resize(n+1, -1);
  cout << func(n) << "\n";
  return 0;
}
