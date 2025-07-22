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

	ranges::sort(a);
	vector<int> ans(n);
	int idx = 0;
	for (int i = 1; i < n; i += 2) {
		ans[i] = a[idx++];
	}
	for (int i = 0; i < n; i += 2) {
		ans[i] = a[idx++];
	}
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
			cnt++;
	}
	cout << cnt << "\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}