#include <bits/stdc++.h>
using namespace std;
// Kruskal: sx->xet canh nho nhat->nap vao cay khung
int n, m;
struct edge{
    int x, y, w;
};
int sz[100001], parent[100001];
vector<edge> dscanh;

// init dstructure disjoinset
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
    if(u==v) return false; // u,v cung tap hop, k gop duoc
    // kiem tra sz lon hon lam parent
    if(sz[u] > sz[v]){
        parent[v] = u;
        sz[u] += sz[v];
    }
    else{
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true; // u, v co the join
}
void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        edge e{x, y, w};
        dscanh.push_back(e);
    }
}
void kruskal(){
    // sx danh sach trong so tang dan
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)
    ->bool{
        return a.w < b.w;
    });
    // lap
    long long d = 0;
    vector<edge> mst;
    for(int i = 0; i < m; i++){
        if(mst.size() == n-1) break;
        edge e = dscanh[i];
        // mst + e co tao thanh chu trinh?
        if(Union(e.x, e.y)){
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d << endl;
    // for(auto it : mst){
    //     cout << it.x << ' '<<it.y<<' '<<it.w << endl;
    // }
}
int main(){
    int t; cin >> t;
    while(t--){
        nhap();
        init();
        kruskal();
        memset(sz, 0, sizeof(sz));
        memset(parent, 0, sizeof(parent));
        dscanh.clear();
    }

}