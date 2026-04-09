#include <bits/stdc++.h>
using namespace std;

int matrix[1001][1001];
vector<int> ke[1001];
int main(){
    memset(matrix, 0, sizeof(matrix));
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
            if(matrix[i][j]){
                ke[i].push_back(j);
            } 
        }
    }
    for(int i = 1; i <= n; i++){
        for(int x : ke[i]){
            cout << x << ' ';
        }
        cout << endl;
    }
}