// v1 的優化版，直接維護一個單調棧就夠了
class StockSpanner {
    stack<array<int, 2>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!st.empty() && price >= st.top()[0]) {
            cnt += st.top()[1];
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */