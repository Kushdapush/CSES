#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int N;

long long fastpow2(int x){
    long long res = 1;
    long long a = 2;
    while(x > 0){
        if(x&1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return res;
}

int main(){
    cin >> N;
    cout << fastpow2(N) << "\n";
    return 0;
}