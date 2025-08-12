#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (is_sorted(a.begin(), a.end())) {
		cout << "yes\n";
		cout << 1 << " " << 1 << "\n";
		return;
	}

	auto b = a;
	ranges::sort(b);

	int l = 0, r = n - 1;
	while (a[l] == b[l]) {
		l++;
	}
	while (a[r] == b[r]) {
		r--;
	}

	int mx = r, ll = l + 1, rr = r + 1;
	while (l <= mx) {
		if (a[l] != b[r]) {
			cout << "no\n";
			return;
		}
		l++;
		r--;
	}

	cout << "yes\n";
	cout << ll << " " << rr << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}