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

    if (n == m) {
        cout << 0 << "\n";
        return;
    } else if (n > m) {
        cout << n - m << "\n";
        return;
    }

    vector<int> vec;
    vec.push_back(m);

    int half = m, ans = 0;
    while (n < half) {
        half = (half + 1) / 2;
        vec.push_back(half);
    }

    ans += n - half;

    for (int i = vec.size() - 1; i >= 1; i--) {
        if (vec[i] * 2 == vec[i - 1]) {
            ans++;
        } else {
            ans += 1 + vec[i] * 2 - vec[i - 1];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}