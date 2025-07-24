#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dist;

int bfs(int node){
    int last;
    vector<int> d(n+1 , -1);
    queue<int>q;
    q.push(node);
    d[node] = 0;
    dist[node] = max(dist[node], d[node]);
    
    while(q.size() > 0){
        last = q.front();
        q.pop(); 
        for(auto& it : adj[last]){
            if(d[it] == -1){
                q.push(it);
                d[it] = d[last] + 1;
                dist[it] = max(dist[it] , d[it]);
            }
        }
    }
    return last;
}

int main() {
    cin>> n;
    
    adj.resize(n+1);
    dist.resize(n+1, -1);

    for(int i=0 ; i<n-1 ; i++) {
        int x , y;
        cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int lastNode = bfs(1);
    int otherEnd = bfs(lastNode);
    bfs(otherEnd);
    
    for(int i = 1 ; i<n+1 ; i++) cout << dist[i] << " ";

    return 0;
}