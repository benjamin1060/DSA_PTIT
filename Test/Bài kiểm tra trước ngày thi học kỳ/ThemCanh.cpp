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

bool vs[100001] = { false };
vector<int> edge[100001];
int cnt = 0;

void dfs(int x) {
	cnt++;
	vs[x] = true;

	for (auto e : edge[x]) {
		if (!vs[e]) {
			dfs(e);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int l1 = 0;
	int l2 = 0;
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			cnt = 0;
			dfs(i);
			if (i == 1) l1 = cnt;
			else {
				l2 = max(l2, cnt);
			}
		}
	}

	cout << l1 + l2 << endl;
	return 0;
}