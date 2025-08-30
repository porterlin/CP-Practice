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
    i64 n;
    cin >> n;
 
    vector<i64> ans;
    for (i64 i = 10; i + 1 <= n; i *= 10) {
        if (n % (i + 1) == 0) {
            ans.push_back(n / (i + 1));
        }
    }

    ranges::reverse(ans);

    cout << ans.size() << "\n";
    for (auto& a : ans) {
        cout << a << " \n"[a == ans.back()];
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