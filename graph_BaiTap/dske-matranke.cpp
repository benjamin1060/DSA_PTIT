#include <bits/stdc++.h>
using namespace std;

int matrix[1001][1001];

int main(){
    memset(matrix, 0, sizeof(matrix));
    int n; cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){
            int x = stoi(tmp);
            matrix[x][i] = 1;
            matrix[i][x] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}