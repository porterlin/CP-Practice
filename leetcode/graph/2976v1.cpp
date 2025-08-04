class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        vector<vector<long long>> f(26, vector<long long>(26, INF));
        for (int i = 0; i < original.size(); i++) {
            f[original[i] - 'a'][changed[i] - 'a'] = min(f[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (f[source[i] - 'a'][target[i] - 'a'] == INF) {
                    return -1;
                } else {
                    ans += f[source[i] - 'a'][target[i] - 'a'];
                }
            }
        }
        return ans;
    }
};