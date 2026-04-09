// theo thứ tự duyệt xong
// thằng nào là cha đứng trước con
// thằng con xong trước thì thằng cha xong trước
// đỉnh u duyệt xong -> cho vào stack

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
int visited[1005];
stack<int> st;
void dfs(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    st.push(u);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}