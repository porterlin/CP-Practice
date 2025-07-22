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

	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			ok = false;
			break;
		}
	}

	if (ok) {
		cout << "NO\n";
		return;
	}

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]].push_back(i);
	}

	cout << "YES\n";
	vector<pair<int, vector<int>>> gangs(mp.begin(), mp.end());
	for (int i = 0; i < gangs.size() - 1; i++) {
		for (int j = 0; j < gangs[i].second.size(); j++) {
			cout << gangs[i].second[j] + 1 << " " << gangs[i + 1].second[0] + 1 << "\n";
		}
	}
	for (int i = 1; i < gangs[gangs.size() - 1].second.size(); i++) {
		cout << gangs[gangs.size() - 1].second[i] + 1 << " " << gangs[0].second[0] + 1 << "\n";
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