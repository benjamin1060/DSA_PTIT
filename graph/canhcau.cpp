#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
vector<pair<int,int>> dscanh;
int n, m; 

void DFS(int u, int s, int t){
    visited[u] = true;
    for(int v : ke[u]){
        if((u==s&&v==t)||(u==t&&v==s)){
            continue;
        }
        if(!visited[v]){
            DFS(v, s, t);
        }
    }
}
int tplt(int s, int t){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++count;
            DFS(i, s, t);
        }
    }
    return count;
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <=n; i++)ke[i].clear();
        dscanh.clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
            dscanh.push_back({x, y});
        }
        for(int i = 1; i <= n; i++){
            sort(ke[i].begin(), ke[i].end());
        }
        memset(visited, false, sizeof(visited));
        int cnt = tplt(0, 0);
        for(auto it : dscanh){
            memset(visited, false, sizeof(visited));
            for(int i = 1; i <= n; i++) ke[i].clear();
            int x = it.first;
            int y = it.second;
            if(cnt < tplt(x, y)){
                cout << it.first << ' '<<it.second<<' ';
            }
        }
        cout << endl;
    }

}