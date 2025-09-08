class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), inf = 1e9 + 1, mx = ranges::max(nums), cnt = 0;
        vector<int> ans(n, inf);
        stack<int> st;
        for (int i = 0; cnt < n; i = (i + 1) % n) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                cnt++;
                st.pop();
            }
            if (nums[i] == mx) {
                ans[i] = -1;
                cnt++;
                continue;
            }
            if (ans[i] == inf) {
                st.push(i);
            }
        }
        return ans;
    }
};