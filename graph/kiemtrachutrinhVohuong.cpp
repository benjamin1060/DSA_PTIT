#include <bits/stdc++.h>
using namespace std;

// backedge - co back edge = co chu trinh
int n, m;
int ok;
vector<int> ke[1001];
bool visited[1001];
int parent[1001];

void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v] = u;
            DFS(v);
        }
        else if(v != parent[u]){
            ok = 1;
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <=n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
    // luu y do thi co nhieu tp lien thong, xet chu trinh
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    if(ok == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}