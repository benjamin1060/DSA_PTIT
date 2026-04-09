#include <bits/stdc++.h>
using namespace std;
int n, m;
bool solve(int n, int m){
    vector<int> ke[n + 5];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        for(int &j : ke[i]){
            if(ke[i].size() != ke[j].size()){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        if(solve(n, m)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}