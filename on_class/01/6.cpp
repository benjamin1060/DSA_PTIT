#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
string k = "xin chao";
int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        long long st[n+3] = {};
        st[0] = st[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = i - k; j < i; j++){
                if(j < 0) continue;
                (st[i] += st[j] % mod) %= mod;
            }
        }
        cout << st[n] << endl;
    }
    return 0;
}

