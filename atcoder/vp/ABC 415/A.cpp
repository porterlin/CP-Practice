#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, a, x;
	cin >> n;
	unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> a;
		st.insert(a);
	}
	cin >> x;
	if (st.contains(x)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}