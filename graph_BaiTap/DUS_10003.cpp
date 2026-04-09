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
    int t; cin >> t;
    while(t--){
        
    }
}