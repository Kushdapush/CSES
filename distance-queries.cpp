#include <bits/stdc++.h>
using namespace std;

int n, q;
int LOG;
vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int par) {
    up[node][0] = par;
    for (int j = 1; j < LOG; j++) {
        if (up[node][j-1] != -1)
            up[node][j] = up[up[node][j-1]][j-1];
        else
            up[node][j] = -1;
    }

    for (int child : tree[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    LOG = 0;
    while ((1 << LOG) <= n) LOG++;

    tree.resize(n + 1);
    up.assign(n + 1, vector<int>(LOG, -1));
    depth.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    depth[1] = 0;
    dfs(1, -1);

    while (q--) {
        int a, b, LCA;
        cin >> a >> b;
        int p = a , q = b;
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i)) {
                a = up[a][i];
            }
        }

        if (a == b) {
            LCA = a;
            cout << depth[p] + depth[q] - 2*depth[LCA] << endl;
            continue;
        }

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != -1 && up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }

        LCA = up[a][0];
        cout << depth[p] + depth[q] - 2*depth[LCA] << endl;
    }

    return 0;
}
