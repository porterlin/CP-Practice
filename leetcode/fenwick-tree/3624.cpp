template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    FenwickTree(int n): tree(n + 1) {}

    void add(int x, T val) {
        for (int i = x + 1; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    T pre(int i) const {
        T res = 0;
        while (i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }

    T rangeSum(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r + 1) - pre(l);
    }
};

class Solution {
public:
    int calDepth(long long a) {
        int depth = 0;
        while (a > 1) {
            a = popcount((unsigned long long)a);
            depth++;
        }
        return depth;
    }

    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        vector<FenwickTree<int>> t(6, FenwickTree<int>(n));
        for (int i = 0; i < nums.size(); i++) {
            int depth = calDepth(nums[i]);
            if (depth > 5) {
                continue;
            }
            t[depth].add(i, 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                ans.push_back(t[q[3]].rangeSum(q[1], q[2]));
            } else {
                t[calDepth(nums[q[1]])].add(q[1], -1);
                t[calDepth(q[2])].add(q[1], 1);
                nums[q[1]] = q[2];
            }
        }
        return ans;
    }
};