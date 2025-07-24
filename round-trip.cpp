#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, parent;
int start = -1, endd = -1;

bool dfs(int node, int par) {
    vis[node] = 1;
    for (int nei : adj[node]) {
        if (nei == par) continue;
        if (vis[nei]) {
            start = nei;
            endd = node;
            return true;
        }
        parent[nei] = node;
        if (dfs(nei, node)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endd; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
