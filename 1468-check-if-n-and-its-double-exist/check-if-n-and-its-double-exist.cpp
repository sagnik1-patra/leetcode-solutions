class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        
        for (int x : arr) {
            // check double
            if (st.count(2 * x)) return true;
            
            // check half (only if even)
            if (x % 2 == 0 && st.count(x / 2)) return true;
            
            st.insert(x);
        }
        
        return false;
    }
};