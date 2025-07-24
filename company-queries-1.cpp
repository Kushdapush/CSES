#include <bits/stdc++.h>
using namespace std;

int n, q, LOG;
vector<int> parent;
vector<vector<int>> up;

int main() {
    cin >> n >> q;
    LOG = log2(n) + 1;

    parent.resize(n+1);
    parent[1] = -1;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    up = vector<vector<int>>(n+1, vector<int>(LOG + 1, -1));

    for (int i = 1; i <= n; i++) {
        up[i][0] = parent[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= LOG; j++) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int i = 0; i <= LOG; i++) {
            if ((1 << i) & k) {
                if (x == -1) break;
                x = up[x][i];
            }
        }

        cout << x << endl;
    }

    return 0;
}
