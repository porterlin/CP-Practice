#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, b;
	cin >> n >> b;

	cout << n << "=";

	string ans;
	while (n != 0) {
		int r = n % b;
		n /= b;
		if (r < 0) {
			r -= b;
			n++;
		}
		if (r > 9) {
			ans.push_back(r - 10 + 'A');
		} else {
			ans.push_back(r + '0');
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "(base" << b << ")\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}