#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x){
            cout << mid << endl;
            return true;
        }
        else if (a[mid] < x)
            // Tìm kiếm ở bên phải
            left = mid + 1;
        else
            // Tìm kiếm ở bên trái
            right = mid - 1;
    }
    cout << "can not be found" << endl;
    return false;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k; cin >> k;
    binarySearch(a, n, k);
}