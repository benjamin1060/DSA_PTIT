// kết bạn- 2 đỉnh luôn có đường đi
// đồ thị hoàn hảo -> tplt phải hoàn hảo
// số cạnh tối đa của tplt
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> ke[100005];
int visited[100005];

void dfs(int u){
    visited[u] = true;
    cnt++;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <=100005; i++) ke[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int canh_hoan_hao = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[1]){
                cnt = 0;
                dfs(i);
                canh_hoan_hao += cnt*(cnt-1)/2;
            }
        }
        cout << canh_hoan_hao << " " << m << endl;
        if(m==canh_hoan_hao) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
