#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k;
	cin >> n >> k;
	unordered_set<int> st;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		st.insert(vec[i]);
	}

	if (st.size() > k) {
		cout << -1 << "\n";
		return;
	} else if (n == k) {
		cout << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << vec[i] << " \n"[i == n - 1];
		}
		return;
	}

	vector<int> buf(st.begin(), st.end());
	ranges::sort(buf);
	cout << k * vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++) {
		if (i == vec.size() - 1) {
			for (int i = 0; i < k; i++) {
				cout << buf[i % buf.size()] << " \n"[i == k - 1];
			}
			break;
		}
		for (int i = 0; i < k; i++) {
			cout << buf[i % buf.size()] << " ";
		}
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