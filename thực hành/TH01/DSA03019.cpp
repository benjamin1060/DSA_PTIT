#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
int mod = 1e9 + 7;

int main(){
    int t; cin >> t;

    while(t--){
        ll p, q; cin >> p >> q;
        vector<string> V;
        while(p > 0){
            while(p > q){
                V.pb("1/1");
                p -= q;
            }
            if(q % p == 0){
                string tmp = "1/";
                tmp += to_string(q/p);
                V.pb(tmp);
                break;
            }else{
                int x = q / p + 1;
                string tmp = "1/";
                tmp += to_string(x);
                V.pb(tmp);
                p = p * x - q;
                q = x * q;
            }
        }
        if(V.size()){
            for(int i = 0; i < V.size(); i++){
                if(i != V.size() - 1)
                    cout << V[i] << " + ";
                else 
                    cout << V[i] << endl;
            }
        }
    }
}
