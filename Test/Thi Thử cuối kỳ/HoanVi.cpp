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
	vector<int> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}

	while (next_permutation(v.begin(), v.end())) {
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			sum += v[i] - v[i + 1];
		}
		if (sum > 0) {
			for (auto i : v) cout << i << " ";
			cout << endl;
		}
	}

	return 0;
}