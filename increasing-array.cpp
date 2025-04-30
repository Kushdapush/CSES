#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    long ans =  0;
    
    for(int i=0 ; i<n  ; i++){
        cin >> nums[i];
        if(i>0){
            int diff = nums[i-1] - nums[i];
            if(diff > 0){
                ans+=diff;
		nums[i] += diff;
            }
        }
    }
    
    cout  << ans << "\n";
    
    return 0;
}