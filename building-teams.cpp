#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> color(n + 1, 0);
    queue<int> q;

    for (int start = 1; start <= n; ++start) {
        if (color[start] != 0) continue;
        color[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : adj[node]) {
                if (color[neighbor] == 0) {
                    color[neighbor] = 3 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}
