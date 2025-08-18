#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    cin >> n;

    vector<int> h1(n), h2(n);
    for (int i = 0; i < n; i++) {
        cin >> h1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h2[i];
    }

    vector<vector<i64>> dp(n, vector<i64>(3));
    dp[0][1] = h1[0];
    dp[0][2] = h2[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + h1[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + h2[i];
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}