// tim so cap sao cho d[i,j] = d[1,i]-d[1,j];
// tim so luong con chau -> thang tuot 
// tong so luong con chau laf d[i,j]
#include <bits/stdc++.h>
using namespace std;
int visited[1001];
vector<int> ke[1001];
int n, m;
int res;
int dfs(int u){
    int cnt = 1;
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            res+= dfs(v);
        }
    }
    res += cnt;
    return cnt;
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <= 1001; i++) ke[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
                int x, y; cin >> x >> y;
                ke[x].push_back(y);
                ke[y].push_back(x);
            }
        dfs(1); cout << res;
    }

}