#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s;
	int n;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] == '_') {
			if (s[i - 1] == '(')
				s[i] = ')';
			else
				s[i] = '(';
		} else if (s[i] == '_') {
			s[i] = '(';
		}
	}

	int ans = 0;
	stack<pair<char, int>> st;
	for (int i = 0; i < n; i++) {
		if (!st.empty() && st.top().first == '(' && s[i] == ')') {
			ans += i - st.top().second;
			st.pop();
			continue;
		}
		st.push({s[i], i});
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