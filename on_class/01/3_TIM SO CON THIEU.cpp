#include <bits/stdc++.h>
using namespace std;

void missingNum(vector<int> &a, int n){
    long long fullSum = 0;
    long long missingSum = 0;
    for(int i = 0; i < n-1; i++){
        missingSum += a[i];
    }
    fullSum = (long long)n * (n+1) / 2;
    cout << fullSum - missingSum << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n-1);
        for(int i = 0; i < n-1; i++){
            int tmp;
            cin >> tmp;
            a[i] = tmp;
        }
        missingNum(a, n);
    }
    return 0;
}