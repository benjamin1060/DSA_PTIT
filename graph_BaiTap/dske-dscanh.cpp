#include <bits/stdc++.h>
using namespace std;

void xuly(int i, string s){
    stringstream ss(s);
    string tmp;
    vector<int> v;
    while(ss >> tmp){
        int j = stoi(tmp);
        // if(j > i) cout << i << " " << j << endl;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    for(int j : v){
        cout << i << " " <<j << " ";
    }
}
int main(){
    int n; cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        xuly(i, s);
    }
}