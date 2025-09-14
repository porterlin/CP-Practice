class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        ranges::sort(cars);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && cars[i].second >= cars[st.top()].second) {
                st.pop();
            }
            st.push(i);
        }
        return st.size();
    }
};