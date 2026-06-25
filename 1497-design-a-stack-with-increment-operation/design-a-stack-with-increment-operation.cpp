class CustomStack {
public:
    int maxSize;
    vector<int> st;
    vector<int> lazy; // renamed
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
            lazy.push_back(0);
        }
    }
    
    int pop() {
        if (st.empty()) return -1;
        
        int i = st.size() - 1;
        int res = st[i] + lazy[i];
        
        // propagate increment
        if (i > 0) {
            lazy[i - 1] += lazy[i];
        }
        
        st.pop_back();
        lazy.pop_back();
        
        return res;
    }
    
    void increment(int k, int val) { // renamed function (optional but safer)
        int i = min(k, (int)st.size()) - 1;
        if (i >= 0) {
            lazy[i] += val;
        }
    }
};