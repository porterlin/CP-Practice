#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	int cnt = 0;
	for (auto& c : s) {
		if (c == '1')
			cnt++;
	}

	if (k <= n / 2 && cnt > k)
		cout << "Bob\n";
	else
		cout << "Alice\n";
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