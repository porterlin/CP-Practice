#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	vector<string> ans;
	auto dfs = [&](auto&& dfs, string cur, int cnt) {
		if (cnt == k) {
			ans.push_back(cur);
			return;
		}

		for (int i = 0; i < n; i++) {
			dfs(dfs, cur + s[i], cnt + 1);
		}
	};

	dfs(dfs, "", 0);
	sort(ans.begin(), ans.end());
	cout << ans[x - 1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}