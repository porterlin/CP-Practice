#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	ranges::sort(vec);

	int mn = INT_MAX;
	int a, b;
	for (int i = 1; i < n; i++) {
		if (vec[i] - vec[i - 1] < mn) {
			mn = vec[i] - vec[i - 1];
			a = vec[i - 1];
			b = vec[i];
		}
	}

	int s = a, t = b;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		if (vec[i] == a) {
			a = -1;
			continue;
		} else if (vec[i] == b) {
			b = -1;
			continue;
		}

		if (vec[i] >= s) {
			v1.push_back(vec[i]);
		} else {
			v2.push_back(vec[i]);
		}
	}

	cout << s << " ";
	for (auto& x : v1) {
		cout << x << " ";
	}
	for (auto& x : v2) {
		cout << x << " ";
	}
	cout << t << "\n";
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