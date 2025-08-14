#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, k;
	cin >> n >> k;

	multiset<i64> s, t;
	for (int i = 0; i < n; i++) {
		i64 a;
		cin >> a;
		s.insert(a);
	}
	for (int i = 0; i < n; i++) {
		i64 a;
		cin >> a;
		t.insert(a % k);
	}

	for (auto& a : s) {
		i64 pos = a % k, neg = abs(a - (a / k + 1) * k) % k;
		if (t.contains(pos)) {
			t.erase(t.find(pos));
		} else if (t.contains(neg)) {
			t.erase(t.find(neg));
		}
	}

	cout << (t.size() > 0 ? "NO\n" : "YES\n");
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