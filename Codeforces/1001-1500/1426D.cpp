#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	unordered_set<i64> st = {0};
	i64 sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (st.contains(sum)) {
			ans++;
			sum = a[i];
			st = {0};
		}
		st.insert(sum);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}