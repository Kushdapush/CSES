#include <bits/stdc++.h>
using namespace std;

void twoKnigtsSoln(int n){
    long totalWays = ((long) n * n * (n * n - 1)) / 2;
    long attackingWays = 4 * (n - 1) * (n - 2);
    
    cout <<  totalWays - attackingWays << "\n";
}

int main() {
    int n;
    cin >> n;
    int m = n;
    while(n){
        twoKnigtsSoln(m-n+1);
        n--;
    }
    return (0);
}