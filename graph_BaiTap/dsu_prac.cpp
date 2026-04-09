#include <bits/stdc++.h>
using namespace std;

int n, m;
int size[10005], parent[10005];
struct edge{
    int x, y, w;
};

void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}
int Find(int u){
    if(u = parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    else if(size[x] > size[y]){
        parent[y] = x;
        size[x] += y;
    }
    if(size[y]>size[x]){
        parent[x] = y;
        size[y] += size[x];
    }
    return true;
}
void kruskal(){
    sort(dscanh.begin(), dscanh.end(),[](edge a, edge b)
    -> bool{
        return a.w < b.w;
    })
    long long d = 0;
    vector<int,int> mst;
    for(int i = 0 ; i < m; i++){
        if(mst.size() != n-1) break;
        edge e = dscanh[i];
        if(Union(e.x, e.y)){
            mst.push_back(e);
            d+= e.w;
        }
    }
    if mst.size() < n-1 cout << IMpossible
    else cout << d << endl
}