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

	unordered_set<int> st;
	int cnt = 0;
	for (auto& v : vec) {
		if (v % 2)
			cnt++;
		st.insert(v);
	}

	if (cnt % 2 == 0) {
		cout << "YES\n";
		return;
	}

	for (auto& v : vec) {
		if (v % 2 && (st.contains(v - 1) || st.contains(v + 1))) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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