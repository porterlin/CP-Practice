// 自己寫的
class StockSpanner {
    stack<int> st;
    vector<array<int, 2>> sp;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!st.empty() && price >= sp[st.top()][0]) {
            cnt += sp[st.top()][1];
            st.pop();
        }
        st.push(sp.size());
        sp.push_back({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */