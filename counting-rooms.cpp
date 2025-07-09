#include <bits/stdc++.h>
using namespace std;

int n;
int m;

vector<vector<bool>>vis;
vector<vector<char>>grid;

vector<int> dy = {1 , 0 , -1 , 0};
vector<int> dx = {0 , -1 , 0 , 1};

bool isValid(int i, int j){
    return (i < n && i>= 0 && j <m && j >= 0);
}

void bfs(int i, int j){
    queue<vector<int>> q;
    q.push({i,j});
    
    while(q.size()){
        vector<int> cell = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int newX = cell[0] + dx[i];
            int newY = cell[1] + dy[i];
            if(isValid(newX , newY) && vis[newX][newY] == false && grid[newX][newY] == '.'){
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vis.resize(n, vector<bool>(m , false));
    grid.resize(n, vector<char>(m));
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j];
        }
    }
    
    int cnt = 0;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == '.' && vis[i][j] == false){
                vis[i][j] = true;
                cnt++;
                bfs(i,j);
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}