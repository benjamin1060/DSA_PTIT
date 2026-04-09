#include <bits/stdc++.h>
using namespace std;

int n, s1, s2, t1, t2;
int a[1005][1005];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{s1,s2}, 0});
    a[s1][s2] = 0;
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int i = it.first.first;
        int j = it.first.second;
        int d = it.second;
        for(int k = 0; k < 8; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i == t1 && j == t2) return d;
            if(i1>=1&&i1<=n&&j1>=n&&j1<=n&&a[i1][j1]==1){
                q.push({{i1, j1}, d+1});
                a[i1][j1] = 0;
            }
        }    
    }
    return -1;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    cout << bfs() << endl;
}