#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n0, n1, n2;
	cin >> n0 >> n1 >> n2;

	if (n1 == 0) {
		if (n0 != 0)
			cout << string(n0 + 1, '0') << "\n";
		else
			cout << string(n2 + 1, '1') << "\n";
		return;
	}

	string ans = string(n0 + 1, '0') + string(n2 + 1, '1');

	while (n1 > 1) {
		if (ans.back() == '0')
			ans.push_back('1');
		else
			ans.push_back('0');
		n1--;
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