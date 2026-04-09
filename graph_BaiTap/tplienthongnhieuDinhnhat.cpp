#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
int cnt = 0;
void DFS(int u){
    cnt++;
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <= 10002; i++) ke[i].clear();
        memset(visited, false, sizeof(visited));
        int n, m; cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int dem = 1;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                cnt = 0;
                DFS(i);
                dem = max(dem, cnt);
            }
        }
        cout << dem << endl;
    }
}