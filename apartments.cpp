#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> budget(n), apts(m);
    for(int i=0 ; i<n ; i++) cin >> budget[i];
    for(int i=0 ; i<m ; i++) cin >> apts[i];
    
    sort(budget.begin(), budget.end());
    sort(apts.begin(), apts.end());
    
    int cnt = 0;
    int i=0 , j=0;
    while(i < n && j < m){
        if(apts[j] <= budget[i]+k && apts[j] >= budget[i]-k){
            cnt++;
            i++;
            j++;
        } else {
            if(apts[j] < budget[i]) j++;
            else i++;
        }
    }
    cout << cnt << endl;
}
