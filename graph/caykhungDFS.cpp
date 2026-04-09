// ban chat cay khung la cang [u,v]
#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
vector<int> ke[1001];
vector<pair<int,int>> mst;
int n, m, u;
// ds ke
void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            mst.push_back({u,v});
            DFS(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i=1; i <=1000;i++) ke[i].clear();
        memset(visited,false,sizeof(visited));
        mst.clear();
        cin >> n >> m >> u;
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        DFS(u);
        if(mst.size() != n - 1){
            cout << -1 << endl;
        }
        else{
            for(auto x : mst){
                cout << x.first << ' '<<x.second << endl;
            }
        }
    }
}

