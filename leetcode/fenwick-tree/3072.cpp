template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    FenwickTree(int n): tree(n + 1) {}

    void add(int x) {
        for (int i = x + 1; i < tree.size(); i += i & -i) {
            tree[i]++;
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
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        auto sorted = nums;
        ranges::sort(sorted);
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        vector<int> a1 = {nums[0]}, a2 = {nums[1]};
        FenwickTree<int> t1(m), t2(m);
        t1.add(ranges::lower_bound(sorted, nums[0]) - sorted.begin());
        t2.add(ranges::lower_bound(sorted, nums[1]) - sorted.begin());

        for (int i = 2; i < nums.size(); i++) {
            int pos = ranges::lower_bound(sorted, nums[i]) - sorted.begin();
            int g1 = a1.size() - t1.pre(pos + 1);
            int g2 = a2.size() - t2.pre(pos + 1);
            
            if (g1 > g2 || (g1 == g2 && a1.size() <= a2.size())) {
                a1.push_back(nums[i]);
                t1.add(pos);
            } else {
                a2.push_back(nums[i]);
                t2.add(pos);
            }
        }

        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};