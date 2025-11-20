template<typename T, typename Compare = less<T>>
class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt;
    size_t sz = 0;

    void apply_remove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    void remove(T x) {
        remove_cnt[x]++;
        sz--;
    }

    T top() {
        apply_remove();
        return pq.top();
    }

    T pop() {
        apply_remove();
        sz--;
        T x = pq.top();
        pq.pop();
        return x;
    }

    void push(T x) {
        if (remove_cnt[x] > 0) {
            remove_cnt[x]--;
        } else {
            pq.push(x);
        }
        sz++;
    }
};