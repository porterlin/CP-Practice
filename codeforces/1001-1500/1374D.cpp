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
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (k - a % k != k) {
            mp[k - a % k]++;
        }
    }

    i64 x = 0;
    for (auto it = mp.begin(); !mp.empty();) {
        if (it == mp.end()) {
            it = mp.begin();
        }
        auto& [key, val] = *it;
        if (key >= x % k) {
            x += key - x % k + 1;
        } else {
            x += k - x % k + key + 1;
        }
        val--;
        if (val == 0) {
            auto it1 = it;
            ++it;
            mp.erase(it1);
        } else {
            ++it;
        }
    }

    cout << x << "\n";
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