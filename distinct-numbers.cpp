#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<int> nums;
    for(int i=0 ; i<n ; i++){
        int x;
        cin >> x;
        nums.insert(x);
    }
    
    cout << nums.size() ; 
    
}
