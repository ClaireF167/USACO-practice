#include <bits/stdc++.h>
using namespace std;


bool visited[3000];
vector<vector<int>> adj(3000);
vector<int> closeOrder(3000);
vector<bool> closed(3000);

struct ConnectedBarns{
    int a, b;
};

void dfs(int v){
    visited[v]=true;
    for(int w: adj[v]){
        if (!visited[w]&&!closed[w]){
            dfs(w);
        }
    }
}

int main() {
    freopen ("closing.in","r",stdin);
    freopen ("closing.out","w",stdout);
    //input
	int n, m;
    cin >> n >> m;
    vector<ConnectedBarns> temp(m);
    for(int i = 0; i < m; i++){
        cin >> temp[i].a >> temp[i].b;
    }
    for(int i = 0; i < n; i++){
        cin >> closeOrder[i];
        closeOrder[i]--;
    }

    //adj list
    for(int i = 0; i < m; i++){
        int u = temp[i].a-1;
        int v = temp[i].b-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //return??
    for(int i = 0; i < n; i++){


        for(int j = 0; j < n; j++){
            visited[j]=false;
        }

        int search = -1;
        for (int j = 0; j < n; j++){
            if(!closed[j]){
                search = j;
                break;
            }
        }
        if(search == -1){
            cout << "YES\n";
            continue;
        }


        dfs(search);

        bool ok = true;
        for(int i = 0; i < n; i++){
            if(!closed[i] && !visited[i]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
        closed[closeOrder[i]]=true;

        
    }
}
