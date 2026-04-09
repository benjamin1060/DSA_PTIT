#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
vector<int> ke[1001];
int a[1001][1001];
vector<pair<int, int>> dscanh;
int n, m;
// ds ke
void DFS1(int u){
    cout << u << " ";
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS1(v);
        }
    }
}
int main(){
    // Liên thông hay không?
    // Chạy dfs(1) -> kiểm tra visited
    // liên thông phải duyệt qua hết - vô hướng
    // Thành phần liên thông - số lần gọi dfs để 
    // duyệt hết toàn đỉnh. 
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS1(1); dem++;
        }
    }
    cout << dem << endl;
}



// ma tran ke
// void DFS2(int u){
//     cout << u << " ";
//     visited[u] = true;
//     for(int i = 1; i <= n; i++){
//         if(!visited[a[u][i]]){
//             DFS2(i);
//         }
//     }
// }

// dscanh
// void DFS3(int u){
//     cout << u << " ";
//     visited[u] = true;
//     for(auto it : dscanh){
//         if(it.first == u){
//             if(!visited[it.second]){
//                 DFS3(it.second);
//             }
//         }
//         else if(it.second == u){
//             if(!visited[it.first]){
//                 DFS3(it.first);
//             }
//         }
//     }
// }