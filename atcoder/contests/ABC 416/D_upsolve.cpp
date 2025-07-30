#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, m;
	cin >> n >> m;
	multiset<i64> st;
	vector<i64> b(n);
	for (i64 i = 0; i < n; i++) {
		i64 a;
		cin >> a;
		a %= m;
		st.insert(a);
	}
	for (i64 i = 0; i < n; i++) {
		cin >> b[i];
		b[i] %= m;
	}

	i64 ans = 0;
	for (i64 i = 0; i < n; i++) {
		auto it = st.lower_bound(m - b[i]);
		if (it == st.end()) {
			it = st.begin();
		}

		ans += (*it + b[i]) % m;
		st.erase(it);
	}
	cout << ans << "\n";
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