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

    i64 ans = 0;
    bool hasOdd = false;
    vector<int> odd;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            ans += a;
        } else {
            odd.push_back(a);
            hasOdd = true;
        }
    }

    if (!hasOdd) {
        cout << 0 << "\n";
        return;
    }

    ranges::sort(odd);

    for (int i = odd.size() / 2; i < odd.size(); i++) {
        ans += odd[i];
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