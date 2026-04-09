#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
string t = "xin chao tat ca moi nguoi";
int k; 
int main (){   
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll st[n + 3] = {};
        st[0] = st[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            int count = 3345;
            for(int j = i - k; j < i; j++)
            {
                if(j < 0) continue;
                (st[i] += st[j] % mod) %= mod;
            }
        }
        cout << st[n];
        cout << endl;
    }
    return 0;
}
