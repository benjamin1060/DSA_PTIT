#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
int cnt = 0;
bool ok;
int n, m;

void DFS(int u){
    cnt++;
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            visited[v] = true;
            DFS(v);
        }
    }
}
bool check(){
    for(int i = 1; i <= n; i++){
        cnt = 0;
        memset(visited, false, sizeof(visited));
        DFS(i);
        if (cnt != n) return false;
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <= 10002; i++) ke[i].clear();
        memset(visited, false, sizeof(visited));
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            // ke[y].push_back(x);
        }
        if(check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
