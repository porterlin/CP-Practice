#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		if (str[i] == '1') {
			int b = i + k;
			i++;
			for (; i < n && i <= b; i++) {
				str[i] = '2';
			}
			i--;
		}
	}

	int cnt = 0;
	vector<int> vec;
	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == '1') {
			vec.push_back(cnt);
			cnt = 0;
			int b = i - k;
			for (i--; i >= 0 && i >= b; i--) {
				str[i] = '2';
			}
			i++;
		} else if (str[i] == '0') {
			cnt++;
		}
	}

	if (cnt > 0)
		vec.push_back(cnt);

	int ans = 0;
	for (auto& c : vec) {
		ans += ceil(c / (double)(k + 1));
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