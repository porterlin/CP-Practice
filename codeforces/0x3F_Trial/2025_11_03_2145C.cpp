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

    string s;
    cin >> s;

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == 'a' ? 1 : -1);
    }

    if (pre[n] == 0) {
        cout << 0 << "\n";
        return;
    }

    int sum = pre[n], ans = n;
    map<int, int> mp;
    for (int i = 0; i < n + 1; i++) {
        if (mp.contains(pre[i] - sum)) {
            ans = min(ans, i - mp[pre[i] - sum]);
        }
        mp[pre[i]] = i;
    }

    cout << (ans == n ? -1 : ans) << "\n";
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