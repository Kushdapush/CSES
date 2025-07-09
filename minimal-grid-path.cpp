#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> grid;
string solve() {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    string result = "";
    result += grid[0][0];

    for (int step = 1; step < 2 * n - 1; ++step) {
        // All reachable positions at this step
        set<pair<int, int>> nextPositions;
        char minChar = 'z';

        // Process current level
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < n && ny < n && !visited[nx][ny]) {
                    minChar = min(minChar, grid[nx][ny]);
                    nextPositions.insert({nx, ny});
                }
            }
        }

        // Filter only those positions where char is minimal
        for (auto [x, y] : nextPositions) {
            if (grid[x][y] == minChar) {
                q.push({x, y});
                visited[x][y] = true;
            }
        }

        result += minChar;
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
    grid.assign(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    cout << solve() << endl;

}