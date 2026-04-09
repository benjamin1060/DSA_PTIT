#include <bits/stdc++.h>
using namespace std;
// dfs tu dinh co nguoi
// xem dinh nguoi di qua thoa man (= du so nguoi)

int k, n, m;
vector<int> ke[1005];
int visited[1005], nguoi[1001];
int d[1005];
void dfs(int u){
    visited[u] = true;
    d[u]++;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    cin >> k >> n >> m;
    for(int &x: nguoi){
        cin >> x;
    }
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        // ke[y].push_back(x);
    }
    for(int x: nguoi){
        memset(visited, false, sizeof(visited));
        dfs(x);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == k) res++;
    }
    cout << res << endl;
}
