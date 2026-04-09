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


int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);

		stack<char> st;

		bool check = true;

		unordered_map<int, int> mp;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') st.push(s[i]);
			else if (s[i] == ')') {
				if (st.empty() || st.top() == '[') {
					check = 0;
					break;
				}
				st.pop();
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() == '(') {
					check = 0;
					break;
				}
				st.pop();
			}
		}

		if (check && st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}