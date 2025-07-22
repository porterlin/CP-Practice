#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, a;
	cin >> n;
	map<i64, i64> mp;
	for (i64 i = 0; i < n; i++) {
		cin >> a;
		mp[a]++;
	}

	vector<pair<i64, i64>> vec(mp.begin(), mp.end());
	i64 size = vec.size();
	vector<i64> dp(size);
	dp[0] = vec[0].first * vec[0].second;
	if (vec[1].first - vec[0].first == 1)
		dp[1] = max(dp[0], vec[1].first * vec[1].second);
	else
		dp[1] = dp[0] + vec[1].first * vec[1].second;

	for (i64 i = 2; i < size; i++) {
		if (vec[i].first - vec[i - 1].first == 1)
			dp[i] = max(dp[i - 1], dp[i - 2] + vec[i].first * vec[i].second);
		else
			dp[i] = dp[i - 1] + vec[i].first * vec[i].second;
	}
	cout << dp[size - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}