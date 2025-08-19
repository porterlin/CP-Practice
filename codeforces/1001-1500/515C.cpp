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

    vector<char> v;
    for (auto& c : s) {
        if (c == '4') {
            v.push_back('3');
            v.push_back('2');
            v.push_back('2');
        } else if (c == '6') {
            v.push_back('5');
            v.push_back('3');
        } else if (c == '8') {
            v.push_back('7');
            v.push_back('2');
            v.push_back('2');
            v.push_back('2');
        } else if (c == '9') {
            v.push_back('7');
            v.push_back('3');
            v.push_back('3');
            v.push_back('2');
        } else if (c != '1' && c != '0') {
            v.push_back(c);
        }
    }

    ranges::sort(v, greater<>());

    for (auto& c : v) {
        cout << c;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}