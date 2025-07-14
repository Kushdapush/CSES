#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> adj;

int dfs(int i){
    int size = 0;
    for (auto& child : adj[i]) {
        size += 1 + dfs(child);
    }
    return ans[i] = size;
}

int main() {
    int n; 
    cin >> n;
    
    adj.resize(n+1);
    ans.resize(n+1);
    
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    
    dfs(1);
    
    for(int i = 1; i <= n; i++) 
        cout << ans[i] << " ";
    return 0;
}
