#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    string s;
    cin >> s;

    if (s == "red") {
        cout << "SSS\n";
    } else if (s == "blue") {
        cout << "FFF\n";
    } else if (s == "green") {
        cout << "MMM\n";
    } else {
        cout << "Unknown\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}