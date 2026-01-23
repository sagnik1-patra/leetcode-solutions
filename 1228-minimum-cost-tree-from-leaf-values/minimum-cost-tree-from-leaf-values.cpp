class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> st;
        st.push(INT_MAX);  // Sentinel

        for (int x : arr) {
            while (st.top() <= x) {
                int mid = st.top();
                st.pop();
                res += mid * min(st.top(), x);
            }
            st.push(x);
        }

        // Clean up remaining elements
        while (st.size() > 2) {
            int mid = st.top();
            st.pop();
            res += mid * st.top();
        }

        return res;
    }
};
