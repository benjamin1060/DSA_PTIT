#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
int cnt, n, m;

void dfs(int u){
    cnt++;
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
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
        int res = 0;
        for(int i = 1; i <= n; i++){
            memset(visited, false, sizeof(visited));
            cnt = 0;
            visited[i] = true;
            if(i==1)dfs(2);
            else dfs(1);
            if(cnt!=n-1) res++;
        }
        cout << res << endl;
    }
}