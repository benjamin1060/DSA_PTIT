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

class Node {
public:
	string s;
	Node* left;
	Node* right;
public:
	Node(string s) {
		this->s = s;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void inOrder(Node* root) {
	if (root != nullptr) {
		inOrder(root->right);
		if (root->s != "N") cout << root->s << " ";
		inOrder(root->left);
	}
}
int main() {
	int t;
	cin >> t;

	cin.ignore();

	while (t--) {
		Node* root = nullptr;
		string s;
		getline(cin, s);

		stringstream ss(s);
		string tmp;

		vector<string> v;

		while (ss >> tmp) v.push_back(tmp);

		int i = 1;
		queue<string> q;
		q.push(v[0]);

		root = new Node(v[0]);

		map<string, Node*> mp;
		mp[v[0]] = root;

		while (!q.empty()) {
			queue<string> q2;

			while (!q.empty()) {
				string cur = q.front();
				q.pop();

				if (i < v.size()) {
					auto node1 = new Node(v[i]);
					auto node2 = new Node(v[i + 1]);

					mp[cur]->left = node1;
					mp[cur]->right = node2;

					if (v[i] != "N") {
						mp[v[i]] = node1;
						q2.push(v[i]);
					}
					if (v[i + 1] != "N") {
						mp[v[i + 1]] = node2;
						q2.push(v[i + 1]);
					}
					i += 2;
				}
			}

			if (i >= v.size()) break;

			q = q2;
		}

		inOrder(root);
		cout << endl;
	}
	return 0;
}