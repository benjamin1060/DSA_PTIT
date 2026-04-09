#include <bits/stdc++.h>
using namespace std;
long long fibo(int n){
    if(n == 0 || n == 1) return n;
    else return fibo(n-1) + fibo(n-2);
}

int nCk(int n, int k){
    if(k == 0 || n == k){
        return 1;
    }
    else{
        return nCk(n-1, k-1) + (n-1, k);
        // cong thuc pascal 
    }
}

int main(){
    int n; cin >> n;
    long long f = fibo(n);
    cout << f << endl;
    return 0;
}
