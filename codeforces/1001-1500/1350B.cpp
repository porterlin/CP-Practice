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

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    vector<int> dp(n + 1, 1);
    for (int i = 2; i < n + 1; i++) {
        for (i64 j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (s[i] > s[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (s[i] > s[i / j]) {
                    dp[i] = max(dp[i], dp[i / j] + 1);
                }
            }
        }
    }

    cout << ranges::max(dp) << "\n";
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