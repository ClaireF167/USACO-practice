#include <bits/stdc++.h>
using namespace std;

char grid[1001][1001];
bool vis[1001][1001];

void dfs(int r, int c, int n, int m){
    vis[r][c]=true;
    //left
    if(c>0&&grid[r][c-1]=='.'&&!vis[r][c-1]){
        dfs(r,c-1, n, m);
    }
    //right
    if (c<m-1&&grid[r][c+1]=='.'&&!vis[r][c+1]){
        dfs(r, c+1, n, m);
    }
    //down
    if(r<n-1&&grid[r+1][c]=='.'&&!vis[r+1][c]){
        dfs(r+1, c, n, m);
    }
    //up
    if(r>0&&grid[r-1][c]=='.'&&!vis[r-1][c]){
        dfs(r-1, c, n, m);
    }
}

int main() {
	int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if (!vis[r][c]&&grid[r][c]=='.'){
                dfs(r, c, n, m);
                count++;
            }
        }
    }
    cout << count;
}
