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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        FenwickTree<int> t(n);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                t.add(i, 1);
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                ans.push_back(t.rangeSum(q[1] + 1, q[2] - 1));
            } else {
                int idx = q[1], val = q[2];
                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i - 1 >= 0 && i + 1 < n && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                        t.add(i, -1);
                    }
                }
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i - 1 >= 0 && i + 1 < n && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                        t.add(i, 1);
                    }
                }
            }
        }
        return ans;
    }
};