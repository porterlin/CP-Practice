#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int ch[26] {};
	string ans;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (vec[i] == ch[j]) {
				ans.push_back('a' + j);
				ch[j]++;
				break;
			}
		}
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