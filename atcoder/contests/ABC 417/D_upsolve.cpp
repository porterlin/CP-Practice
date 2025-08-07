#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int K = 1001;

void solve() {
	int N;
	cin >> N;
	vector<int> P(N), A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i] >> A[i] >> B[i];
	}

	vector<vector<int>> dp(N + 1, vector<int>(K));
	for (int i = 0; i < K; i++) {
		dp[N][i] = i;
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < K; j++) {
			if (j <= P[i]) {
				dp[i][j] = dp[i + 1][j + A[i]];
			} else {
				dp[i][j] = dp[i + 1][max(0, j - B[i])];
			}
		}
	}

	vector<int> pre(N + 1);
	for (int i = 0; i < N; i++) {
		pre[i + 1] = pre[i] + B[i];
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int X;
		cin >> X;

		int idx = upper_bound(pre.begin(), pre.end(), X - K) - pre.begin();
		if (idx == N + 1) {
			cout << X - pre[N] << "\n";
		} else {
			cout << dp[idx][X - pre[idx]] << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}