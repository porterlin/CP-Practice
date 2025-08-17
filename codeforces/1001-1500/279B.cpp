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
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 0, sum = 0;
    for (i64 l = 0, r = 0; r < n; r++) {
        sum += a[r];
        while (sum > t) {
            sum -= a[l++];
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}