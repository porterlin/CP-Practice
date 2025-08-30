#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> diff(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        diff[l]++;
        diff[r + 1]--;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum % 2) {
            s[i] = t[i];
        }
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}