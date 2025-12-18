class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev, curr;

        for (int x : arr) {
            curr.clear();
            curr.insert(x);

            for (int v : prev) {
                curr.insert(v | x);
            }

            for (int v : curr) {
                ans.insert(v);
            }

            prev = curr;
        }

        return ans.size();
    }
};
