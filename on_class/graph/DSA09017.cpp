#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int test;
int n, m, s, t, visited[1001], parent[1001], cnt;
vector<int> adj[1001];

int dfs(int u, int par){
    visited[u] = 1;
    for(int x : adj[u]){
        if(!visited[x]){
            if(dfs(x, u))return 1;
        }
        else if(x != par)return 1;
    }
    return 0;
}

int solve(int n){
    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        if(dfs(i, 0))
            return 1;
    }
    return 0;
}

int main(){
    cin >> test;
    while(test--){
        for(int i = 1; i <= 1000; i++)adj[i].clear();
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if(solve(n))
            cout << "NO\n";
        else 
            cout << "YES\n";
    }
}
/*

*/