#include <bits/stdc++.h>
using namespace std;

int visited[1005];
vector<int> ke[1005];
int n, height[1005];
void dfs(int u){
    visited[u] = true;
    for(int v : ke[u]){
        // la cay nen k can used
        height[v] = height[u] + 1;
        dfs(v);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(x);
        ke[y].push_back(x);
    }
    height[1] = 0;
    dfs(1);
    for(int i = 0; i < n; i++){
        cout << height[i] << " ";
    }
}