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
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (auto& [_, val] : mp) {
        if (val % k > 0) {
            cout << 0 << "\n";
            return;
        }
        val /= k;
    }

    map<int, int> window;
    i64 ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        window[a[r]]++;
        while (window[a[r]] > mp[a[r]]) {
            window[a[l++]]--;
        }
        ans += r - l + 1;
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