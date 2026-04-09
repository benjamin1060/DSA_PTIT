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
#include <numeric>
#include <unordered_set>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


int n, k;
int x[100] = { 0 };
unordered_map<string, int> mp;
vector<int> v;
vector<string> res;

void kiemtra() {
	string s = "";
	for (int i = 1; i <= k; i++) {
		s = s + to_string(v[x[i]]);
	}
	mp[s]++;
	if (mp[s] == 1) res.push_back(s);
}

void tohop(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			kiemtra();
		}
		else tohop(i + 1);
	}
}

int main() {
	cin >> n >> k;

	v.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> v[i];
	x[0] = 0;

	tohop(1);

	sort(res.begin(), res.end());
	for (auto x : res) cout << x << endl;

	return 0;
}