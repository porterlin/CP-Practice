#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    ranges::sort(t);

    unordered_set<int> st;
    i64 sum = 0, ans = 0;
    while (true) {
        auto it = lower_bound(t.begin(), t.end(), sum);
        if (st.contains(it - t.begin())) {
            ++it;
        }
        if (it == t.end() || sum > *it) {
            break;
        }
        st.insert(it - t.begin());
        sum += *it;
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}