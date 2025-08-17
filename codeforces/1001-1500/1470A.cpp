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
    int n, m;
    cin >> n >> m;

    vector<int> k(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    ranges::sort(k, [&](int a, int b) {
        return c[a] > c[b];
    });

    i64 ans = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (l < k[i]) {
            ans += c[l++];
        } else {
            ans += c[k[i]];
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