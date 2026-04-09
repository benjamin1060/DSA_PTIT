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

#define int long long

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

class cv {
public:
	int d, p;
};
main() {
	faster();
	int n;
	cin >> n;

	vector<cv> v(n + 5);

	for (int i = 0; i < n; i++) {
		cin >> v[i].d >> v[i].p;
	}

	sort(v.begin(), v.end(), [](cv& a, cv& b) {
		return a.p > b.p;
		});

	bitset<1000000001> bs;

	int sum = 0;

	for (auto x : v) {
		while (bs[x.d] && x.d) x.d--;

		if (!bs[x.d] && x.d) {
			sum += x.p;
			bs[x.d] = 1;
		}
	}

	cout << sum << endl;
	return 0;

}