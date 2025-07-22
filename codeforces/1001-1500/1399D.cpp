#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int cnt = 2;
	vector<priority_queue<int, vector<int>, greater<>>> vec(2);
	vec[(s[0] - '0' + 1) % 2].push(1);
	vector<int> ans(n);
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		int a = s[i] - '0';
		if (vec[a].empty()) {
			ans[i] = cnt;
			vec[(a + 1) % 2].push(cnt);
			cnt++;
			continue;
		}
		ans[i] = vec[a].top();
		vec[a].pop();
		vec[(a + 1) % 2].push(ans[i]);
	}

	cout << cnt - 1 << "\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
	}
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