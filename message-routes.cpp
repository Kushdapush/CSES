#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<int>par(n+1 , -1);

    
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> vis(n+1);
    
    queue<int> q;
    q.push(1);
    par[1] = -1;
    vis[1] = 1;
    
    while(q.size() > 0){
        int n = q.front();
        q.pop();
        
        for(int neigh : adj[n]){
            if(vis[neigh] == 0){
                vis[neigh] = 1;
                par[neigh] = n;
                q.push(neigh);
            }
        }
    }
    
    if(vis[n] == 0) {cout << "IMPOSSIBLE" << endl; return 0;}
    
    vector<int> ans;
    int curr = n;
    while(curr != 1){
        ans.push_back(curr);
        curr = par[curr];
    }
    ans.push_back(1);
    
    reverse(ans.begin() , ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    return 0;
}