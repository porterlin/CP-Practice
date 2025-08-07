#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		st.insert(a);
	}
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		auto it = st.find(b);
		if (it != st.end())
			st.erase(it);
	}
	vector<int> vec(st.begin(), st.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " \n"[i == vec.size() - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}