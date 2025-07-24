#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int diameter = 0;

int dfs(int node){
    int max1 = 0 , max2 = 0;
    
    for(auto &it : adj[node]){
        int temp = dfs(it);
        if(temp > max1) {
            max2 = max1;
            max1 = temp;
        } 
        else if(temp > max2){
            max2 = temp;
        }
    }
    diameter = max(diameter , max1 + max2);
    return 1 + max(max1 ,max2);
}

int main() {
    int n;
    cin>> n;
    
    adj.resize(n+1);
    
    for(int i=0 ; i<n-1 ; i++) {
        int x , y;
        cin >> x >> y;
        
        adj[x].push_back(y);
    }
    
    int temp = dfs(1);
    
    cout << diameter << endl;

    return 0;
}