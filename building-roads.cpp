#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
vector<int>par;

void bfs(int node, vector<vector<int>> &adj, vector<int> &vis){
    vis[node] = 1;
    
    queue<int> q;
    q.push(node);
    
    while(q.size() > 0){
        int n = q.front();
        q.pop();
        
        for(int neigh : adj[n]){
            if(vis[neigh] == 0){
                vis[neigh] = 1;
                q.push(neigh);
            }
        }
    }
}

int main() {
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> vis(n+1);
    
    int cnt = 0;
    for(int i=1 ; i<=n ; i++){
        if(vis[i] == 0){
            par.push_back(i);
            cnt++;
            bfs(i , adj, vis);
        }
    }
    
    cout << cnt - 1 << endl;
    
    for(int i=1 ; i<par.size() ; i++){
        cout << par[i-1] << " " << par[i] << endl;
    }

    return 0;
}