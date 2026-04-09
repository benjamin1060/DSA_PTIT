#include <bits/stdc++.h>
using namespace std;

// dijkstra tìm đường đi ngắn nhất từ 1 đỉnh tới 
// mọi đỉnh trên đồ thị.
// vô hướng + có hướng
// trọng số không âm
// relax -> thông qua đường đi ngắn nhất -> tìm
int n, m,s; 
vector<pair<int,int>> ke[100001];

void nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
}
void dijkstra(int s){
    vector<int> d(n+1, 1e9);
    d[s] = 0; // khoang cach
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> Q;
    Q.push({0, s});
    while(!Q.empty()){
        // chon dinh u co dg di ngan nhat de relax
        pair<int,int> top = Q.top(); Q.pop();
        int u = top.second, kc = top.first; // kc khoang cach di kem
        if(kc > d[u]) continue;
        // relax
        for(auto it : ke[u]){
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <=n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
int main(){
    int t; cin >> t; 
    while(t--){
        nhap();
        dijkstra(s);
    }
}