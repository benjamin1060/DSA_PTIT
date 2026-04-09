#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int dem = 0;
int tplt[1001];
int parent[1001];
int n, m, s, t;
bool comp(int a, int b){
    return a > b;
}
void nhap(){
    int n, m;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    // uu tien dinh nho hon
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
        // ke[i].end, greater<int>());
        // ke[i].end, comp);
    }
}

void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v] = u;
            DFS(v);
        }
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u); visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : ke[x]){
            if(!visited[y]){
                parent[y] = x;
                q.push(y); visited[y]; 
            }
        }
    }
}
int main(){
    nhap();
    // DFS(s);
    BFS(s); // khong trong so --> duong di ngan nhat
    if(!visited[t]) cout << "NO" << endl;
    else{
        // traceback 
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for(int x : res) cout << x << ' ';
    }
}