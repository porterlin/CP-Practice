#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = a[i] - b[i];
	}

	ranges::sort(c);

	i64 ans = 0;
	for (int i = n - 1, j = 0; i >= 0; i--) {
		while (j < i && c[i] + c[j] <= 0) {
			j++;
		}
		ans += max(i - j, 0);
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}