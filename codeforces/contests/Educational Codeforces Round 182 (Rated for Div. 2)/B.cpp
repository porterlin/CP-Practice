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

    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] > 0) {
            st.erase(p[i]);
        }
    }

    auto it = st.rbegin();
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            p[i] = *it;
            ++it;
        }
    }

    if (ranges::is_sorted(p)) {
        cout << 0 << "\n";
        return;
    }

    int l = 0, r = n - 1;
    while (p[l] == l + 1 || p[r] == r + 1) {
        if (p[l] == l + 1) {
            l++;
        }
        if (p[r] == r + 1) {
            r--;
        }
    }
    cout << r - l + 1 << "\n";
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