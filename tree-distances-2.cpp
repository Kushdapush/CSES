#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> ans;
vector<vector<int>> adj;
vector<long long> dp;
vector<long long> subtree;

void dfs1(int node, int par){
    subtree[node] = 1;
    dp[node] = 0;
    for(int child : adj[node]){
        if(child == par) continue;
        dfs1(child, node);
        subtree[node] += subtree[child];
        dp[node] += dp[child] + subtree[child];
    }
}

void dfs2(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        ans[child] = ans[node] - subtree[child] + n - subtree[child];
        dfs2(child, node);
    }
}

int main() {
    cin >> n;
    ans.resize(n+1);
    adj.resize(n+1);
    dp.resize(n+1);
    subtree.resize(n+1);
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs1(1,0);
    ans[1] = dp[1];
    dfs2(1,0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
