#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char move_dir[] = {'D', 'R', 'U', 'L'};

bool inRange(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    fastio;
    
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }

    pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (inRange(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});

                if (make_pair(nx, ny) == end) {
                    found = true;
                    break;
                }
            }
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }

    vector<char> path;
    pair<int, int> curr = end;
    while (curr != start) {
        pair<int, int> prev = parent[curr.first][curr.second];
        for (int dir = 0; dir < 4; ++dir) {
            if (prev.first + dx[dir] == curr.first && prev.second + dy[dir] == curr.second) {
                path.push_back(move_dir[dir]);
                break;
            }
        }
        curr = prev;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    for (char c : path) cout << c;
    cout << "\n";

    return 0;
}
