#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

int main(){
	int test; cin >> test;
	while(test--){
		int n; cin >> n;
		int a[n];
		set<int> se;
		for(int &x : a){
			cin >> x;
			se.insert(x);
		}
		if(se.size() == 1)
			cout << -1 << endl;
		else{
			auto it = se.begin();
			cout << *it << ' ';
			it++; cout << *it << endl;
		}
	}
}
