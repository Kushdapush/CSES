#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n<=4) {
	if(n == 3 || n == 2) cout <<  "NO SOLUTION" << "\n";
	if(n == 1) cout << 1 <<  " ";
	if(n == 4) cout << 2 << " " << 4 << " " << 1 << " " << 3 << "\n";
        return 0;
    }
    
    vector<int>nums(n);
    int num  = 1;
    
    for(int i=0 ; i<n ; i++){
        if(i%2==0){
            nums[i] = num++;
        }
    }
    
    for(int i = 0 ; i<n ; i++){
        if(i%2 == 1){
            nums[i] = num++;
        }
    }
    
    for(int i : nums){
        cout << i << " ";
    }
    
    return 0;
}