//USACO Silver Dec 2016
#include <bits/stdc++.h>
using namespace std;

struct Cow{
    int x, y, p;
};

bool visited[2000];
vector<vector<int>> adj(2000);
int dfs(int v){
    visited[v]=true;
    int count = 1;
    for(int w : adj[v]){
        if (!visited[w]){
            count+=dfs(w);
        }
    }
    return count;
}

int main() {
	freopen ("moocast.in","r",stdin);
    freopen ("moocast.out","w",stdout);
	int n, x, y, p;
    cin >> n;
    vector<Cow> temp(n);
    for(int i = 0; i < n; i++){
        cin >> temp[i].x >> temp[i].y >> temp[i].p;
    }

//adjacency list
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i==j) continue;
            if ((temp[i].x-temp[j].x)*(temp[i].x-temp[j].x)+(temp[i].y-temp[j].y)*(temp[i].y-temp[j].y)<temp[i].p*temp[i].p){
                adj[i].push_back(j);
            }
        }
    }

//calculate max path
    int maxcount = 1;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[j]=false;
        }
        int count = dfs(i);
        maxcount = max(maxcount, count);
    }

    cout << maxcount << endl;
}
