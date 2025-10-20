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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 suf = 0;
    i64 pre = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            suf += a[i];
        }
    }

    i64 ans = -suf;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            suf -= a[i];
        } else {
            pre += a[i];
        }
        ans = max(ans, pre - suf);
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