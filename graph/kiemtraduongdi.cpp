#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int dem = 0;
int tplt[1001];

void DFS(int u){
    visited[u] = true;
    // cout << u << " ";
    for(int v : ke[u]){
        tplt[v] = dem;
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dem++;
            DFS(i);
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(tplt[x] == tplt[y]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}