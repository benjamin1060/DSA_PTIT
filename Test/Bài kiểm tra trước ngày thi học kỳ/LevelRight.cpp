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
	int x;
	Node* left;
	Node* right;

public:
	Node(int x) {
		this->x = x;
		this->left = nullptr;
		this->right = nullptr;
	}
};

Node* connect(Node* root, int x) {
	if (root == nullptr) {
		Node* n = new Node(x);
		return n;
	}
	else {
		if (x > root->x)
			root->right = connect(root->right, x);
		else
			root->left = connect(root->left, x);
	}

	return root;
}

void levelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		cout << cur->x << " ";

		if (cur->right != nullptr) q.push(cur->right);
		if (cur->left != nullptr) q.push(cur->left);
	}
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);

		Node* root = nullptr;

		for (auto& i : v) {
			cin >> i;

			if (root == nullptr) {
				root = new Node(i);
			}
			else
				root = connect(root, i);
		}

		levelOrder(root);

		cout << endl;
	}

	return 0;
}