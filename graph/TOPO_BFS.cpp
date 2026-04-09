// xóa dần đỉnh - xóa thằng có bán bậc vào = 0;
#include <bits/stdc++.h>
using namespace std;

int n, m;
int bbv[1005];
vector<int> ke[1005];
int visited[1005];

void Kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(bbv[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << ' ';
        for(int v : ke[u]){
            bbv[v]--;
            if(bbv[v] == 0) q.push(v);
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        bbv[y]++;
    }
    Kahn();
}