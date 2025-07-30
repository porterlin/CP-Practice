#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, l, r;
	string s;
	cin >> n >> l >> r >> s;
	l--;
	r--;

	for (int i = l; i <= r; i++) {
		if (s[i] == 'x') {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}