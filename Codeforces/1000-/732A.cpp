#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int k, r;
	cin >> k >> r;

	int ans = 1;
	while (true) {
		if ((k * ans) % 10 == 0 || (k * ans) % 10 == r) {
			cout << ans;
			break;
		}
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}