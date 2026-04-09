#include <bits/stdc++.h>
using namespace std;

int n, m, parent[1005], bac[1005];
int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    else{
        if(bac[x]>bac[y]||bac[x]==bac[y]&&x<y){
            parent[y] = x;
        }
        else parent[x] = y;
    }
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = n; i <= n; i++){
        parent[i] = i;
    }
    vector<pair<int,int>> edge;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        edge.push_back({x, y});
        bac[x]++; bac[y]++;
    }
    for(auto e : edge){
        Union(e.first, e.second);
    }
    // nhom truong -> parent[chinh no]
    for(int i = 1; i <= n; i++){
        if(i == parent[i]) cout << i << ' ';
    }
}