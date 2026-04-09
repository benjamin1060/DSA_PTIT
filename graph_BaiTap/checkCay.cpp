#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10001];
vector<pair<int,int>> dscanh;
bool visited[10001];
int cnt = 0;
int n;

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
bool check1(){
    for(int i = 1; i <=n; i++){
        cnt = 0;
        if(!visited[i]){
            memset(visited, false, sizeof(visited));
            DFS(i);
            if(cnt != n) return false;
        }
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <= 10002; i++) ke[i].clear();
        memset(visited, false, sizeof(visited));
        dscanh.clear();
        cin >> n;
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
            dscanh.push_back({x,y});
        }
        if(dscanh.size() == n-1 && check1()){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}