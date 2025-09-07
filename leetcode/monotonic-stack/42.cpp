class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) { // 也可以用 >=，這樣 stack 中沒有重複元素。在有很多重複元素的情況下，可以使用更少的空間
                int h = height[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int w = i - st.top() - 1;
                ans += w * (min(height[i], height[st.top()]) - h);
            }
            st.push(i);
        }
        return ans;
    }
};