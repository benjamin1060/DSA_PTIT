#include <bits/stdc++.h>
using namespace std;
int n, m;
int nhomTruong;
vector<int> ke[1005];
int bac[1005];
int visited[1005];

void dfs(int u){
    if(bac[u]>bac[nhomTruong]||bac[u]==bac[nhomTruong]&&u<nhomTruong){
        nhomTruong = u;
        visited[u] = true;
        for(int v : ke[u]){
            if(!visited[v]){
                dfs(v);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        bac[x]++; bac[y]++;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            nhomTruong = i;
            dfs(i);
            v.push_back(nhomTruong);
        }
    }
    sort(v.begin(), v.end());
    for(int i : v){
        cout << i << ' ';
    }
}