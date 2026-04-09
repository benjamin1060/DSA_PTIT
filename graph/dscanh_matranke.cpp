#include <bits/stdc++.h>

using namespace std; 
// ma tran ke
// common used: ds canh/ds canh trong so
// pair - struct

// most tối ưu, most áp dụng: ds ke - adjacency list
// vector<int> ke[1001]: array of vectors
// vector<vector<int>> adj[1001]

int a[1005][1005];
int m, n;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


