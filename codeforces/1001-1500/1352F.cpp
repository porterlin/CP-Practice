#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n0, n1, n2;
	cin >> n0 >> n1 >> n2;

	string ans, path;
	auto dfs = [&](this auto && dfs, int a0, int a1, int a2) -> bool {
		if (a0 <= 0 && a1 <= 0 && a2 <= 0) {
			ans = path;
			return true;
		}

		if (a1 > 0) {
			if (path == "") {
				path += "01";
				if (dfs(a0, a1 - 1, a2))
					return true;
				path.clear();
			} else {
				if (path.back() == '0')
					path.push_back('1');
				else
					path.push_back('0');
				if (dfs(a0, a1 - 1, a2))
					return true;
				path.pop_back();
			}

			if (path == "") {
				path += "10";
				if (dfs(a0, a1 - 1, a2))
					return true;
				path.clear();
			} else {
				if (path.back() == '0')
					path.push_back('1');
				else
					path.push_back('0');
				if (dfs(a0, a1 - 1, a2))
					return true;
				path.pop_back();
			}
		}
		if (a0 > 0) {
			if (path == "") {
				path += "00";
				if (dfs(a0 - 1, a1, a2))
					return true;
				path.clear();
			} else {
				if (path.back() == '0')
					path.push_back('0');
				else
					return false;
				if (dfs(a0 - 1, a1, a2))
					return true;
				path.pop_back();
			}
		}
		if (a2 > 0) {
			if (path == "") {
				path += "11";
				if (dfs(a0, a1, a2 - 1))
					return true;
				path.clear();
			} else {
				if (path.back() == '1')
					path.push_back('1');
				else
					return false;
				if (dfs(a0, a1, a2 - 1))
					return true;
				path.pop_back();
			}
		}
		return false;
	};

	dfs(n0, n1, n2);
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