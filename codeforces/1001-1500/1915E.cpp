#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<i64> st{0LL};
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (i % 2 ? a[i] : -a[i]);
        st.insert(pre[i + 1]);
    }

    if (st.size() != n + 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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