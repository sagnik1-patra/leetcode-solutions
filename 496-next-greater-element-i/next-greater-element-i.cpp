class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;   // value -> next greater value
        vector<int> st;                 // monotonic decreasing stack of values

        for (int x : nums2) {
            while (!st.empty() && st.back() < x) {
                next[st.back()] = x;    // x is the next greater for st.back()
                st.pop_back();
            }
            st.push_back(x);
        }
        // Remaining values in stack have no next greater
        for (int v : st) next[v] = -1;

        vector<int> ans;
        ans.reserve(nums1.size());
        for (int v : nums1) ans.push_back(next[v]);
        return ans;
    }
};
