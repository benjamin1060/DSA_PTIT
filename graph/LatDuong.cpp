#include <bits/stdc++.h>
using namespace std;


struct edge{
    int x, y;
};
int n, m, dem, max_current = 1;
int sz[100001], parent[100001];
vector<edge> dscanh;

void init(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}
int Find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u==v) return false;
    else if(sz[u] > sz[v]){
        parent[v] = u;
        sz[u] += sz[v];
    }
    else{
        parent[u] = v;
        sz[v] += sz[u];
    }
    max_current = max({max_current, sz[u], sz[v]});
    return true;
}
int main(){
    cin >> n >> m;
    init();
    int dem = n;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        if(Union(x, y)){
            --dem;
        }
        cout << dem << " "<< max_current << endl;
    }
}