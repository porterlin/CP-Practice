#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

vector<string> cand = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<string> getColor(n);
	unordered_map<string, vector<int>> getIdx;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		getColor[i] = str;
		getIdx[str].push_back(i);
	}

	while (q--) {
		int idx, idy;
		cin >> idx >> idy;
		idx--;
		idy--;

		if (idx > idy)
			swap(idx, idy);

		string x = getColor[idx];
		string y = getColor[idy];

		if (x[0] == y[0] || x[0] == y[1] || x[1] == y[0] || x[1] == y[1]) {
			cout << idy - idx << "\n";
		} else {
			int ans = INT_MAX;
			for (int i = 0; i < 6; i++) {
				if (cand[i] == x || cand[i] == y)
					continue;
				if (getIdx.contains(cand[i])) {
					auto it = ranges::lower_bound(getIdx[cand[i]], idx);
					if (it != getIdx[cand[i]].end())
						ans = min(ans, abs(*it - idx) + abs(*it - idy));
					if (it != getIdx[cand[i]].begin())
						ans = min(ans, abs(*(it - 1) - idx) + abs(*(it - 1) - idy));

					it = ranges::lower_bound(getIdx[cand[i]], idy);
					if (it != getIdx[cand[i]].end())
						ans = min(ans, abs(*it - idx) + abs(*it - idy));
					if (it != getIdx[cand[i]].begin())
						ans = min(ans, abs(*(it - 1) - idx) + abs(*(it - 1) - idy));
				}
			}
			cout << (ans == INT_MAX ? -1 : ans) << "\n";
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