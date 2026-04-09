#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];

void bfs(int u){
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << ' ';
        for(int y : ke[x]){
            if(!visited[y]){
                visited[y] = true;
                q.push(y);
            }
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
            // ke[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
            sort(ke[i].begin(), ke[i].end());
        }
        memset(visited, false, sizeof(visited));
        bfs(u);
        cout << endl;
    }
}