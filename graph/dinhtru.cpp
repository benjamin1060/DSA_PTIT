#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1001];
bool visited[1001];
void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int tplt(){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++count;
            DFS(i);
        }
    }
    return count;
}
void dinhtru(){
    int cnt = tplt();
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(cnt < tplt()){
            cout << i << " ";
        }
    }
}

