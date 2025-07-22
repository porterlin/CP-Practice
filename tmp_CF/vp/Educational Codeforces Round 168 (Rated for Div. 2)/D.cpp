#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

struct Node {
	vector<Node*> children;
	int val;
	Node(int v): val(v) {};
};

void solve() {
	int n;
	cin >> n;
	vector<Node*> a(n + 1, nullptr);
	for (int i = 1; i <= n; i++) {
		int buf;
		cin >> buf;
		a[i] = new Node(buf);
	}
	for (int i = 2; i <= n; i++) {
		int idx;
		cin >> idx;
		a[idx]->children.push_back(a[i]);
	}

	auto dfs = [&](this auto && dfs, Node * node, bool isRoot) -> int {
		if (node->children.size() == 0)
			return node->val;

		int mn = INT_MAX;
		for (int i = 0; i < node->children.size(); i++) {
			mn = min(mn, dfs(node->children[i], false));
		}

		if (node->val < mn && !isRoot) {
			return node->val + (mn - node->val) / 2;
		}
		return mn;
	};

	Node* root = a[1];
	int r = dfs(root, true);
	cout << root->val + r << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}