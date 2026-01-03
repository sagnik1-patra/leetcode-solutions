class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            vals.push_back(curr->val);
        }

        int n = vals.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && vals[i] > vals[st.top()]) {
                ans[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
