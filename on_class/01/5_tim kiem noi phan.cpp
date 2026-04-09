#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right && key >= arr[left] && key <= arr[right]) {
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (key - arr[left]);
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1; // cannot find
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;  cin >> key;

    int index = search(arr, n, key);
    if (index != -1)
        cout << index << endl;
    else
        cout << "Khong tim thay" << endl;

    return 0;
}
