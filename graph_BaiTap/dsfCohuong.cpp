#include <bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
bool visited[1001];
void DFS(int u){
    visited[u] = true;
    cout << u << ' ';
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <= 1001; i++) ke[i].clear();
        int n, m, u; cin >> n >> m >> u;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
        }
        for(int i = 1; i <=n; i++){
            sort(ke[i].begin(), ke[i].end());
        }
        memset(visited, false, sizeof(visited));
        DFS(u);
        
        cout << endl;
    }
}