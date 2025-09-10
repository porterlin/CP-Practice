// 靈神的寫法
class StockSpanner {
    stack<array<int, 2>> st;
    int cur_day = -1;
public:
    StockSpanner() {
        st.push({-1, INT_MAX});
    }
    
    int next(int price) {
        while (!st.empty() && price >= st.top()[1]) {
            st.pop();
        }
        cur_day++;
        int ans = cur_day - st.top()[0];
        st.push({cur_day, price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */