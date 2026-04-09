#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <cstdlib>
#include <bitset>
#include <numeric>
#include <unordered_set>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	int cnt = n / k;
	int m = cnt;
	int i = 0;
	int sum = 0;
	while (k--) {
		for (int j = i + 1; j < i + m; j++) {
			sum += abs(v[j] - v[j - 1]);
		}
		i = i + m;
	}

	cout << sum << endl;
	return 0;
}