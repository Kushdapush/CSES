// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    long n;
    cin >> n;
    vector<long> ans;
    
    while(n!=1){
        ans.push_back(n);
        if(n%2==0){
            n/=2;
        } else {
            n=3*n+1;
        }
    }
    
    for(long i : ans){
        cout << i << " ";
    }
    
    cout << 1 << " ";
    
    return 0;
}