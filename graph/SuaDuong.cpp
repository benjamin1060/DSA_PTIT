#include <bits/stdc++.h>
using namespace std;

int n, m;
int sz[100001], parent[100001];
struct edge{
    int x, y, w;
};
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
    return true;
}
void nhap(){
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        edge e{x,y,w};
        dscanh.push_back(e);
    }
}
void kruskal(){
    sort(dscanh.begin(),dscanh.end(),[](edge a, edge b)
    -> bool{
        return a.w < b.w;
    });
    long long d = 0;
    vector<edge> mst;
    for(int i = 0; i < m; i++){
        if(mst.size() == n-1) break;
        edge e = dscanh[i];
        if(Union(e.x, e.y)){
            mst.push_back(e);
            d += e.w;
        }
    }
    if(mst.size() < n-1) cout << "IMPOSSIBLE" << endl;
    else cout << d << endl;

}