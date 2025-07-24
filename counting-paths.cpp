#include <bits/stdc++.h>
using namespace std;

int n, q;
int LOG;
vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depth;
vector<int> cnt;
vector<int> ans;

void dfs(int node, int par) {
    up[node][0] = par;
    for (int j = 1; j < LOG; j++) {
        if (up[node][j - 1] != -1)
            up[node][j] = up[up[node][j - 1]][j - 1];
        else
            up[node][j] = -1;
    }

    for (int child : tree[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

void dfs2(int node, int par) {
    ans[node] += cnt[node];
    for (auto child : tree[node]) {
        if (child == par) continue;
        dfs2(child, node);
        ans[node] += ans[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    LOG = log2(n) + 1;

    tree.resize(n + 1);
    up.assign(n + 1, vector<int>(LOG, -1));
    depth.resize(n + 1);
    cnt.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    depth[1] = 0;
    dfs(1, -1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int origA = a, origB = b;

        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int i = LOG - 1; i >= 0; i--) {
            if ((diff >> i) & 1) {
                a = up[a][i];
            }
        }

        int lca;
        if (a == b) {
            lca = a;
        } else {
            for (int i = LOG - 1; i >= 0; i--) {
                if (up[a][i] != -1 && up[a][i] != up[b][i]) {
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            lca = up[a][0];
        }

        cnt[origA]++;
        cnt[origB]++;
        cnt[lca]--;
        if (up[lca][0] != -1)
            cnt[up[lca][0]]--;
    }

    dfs2(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
