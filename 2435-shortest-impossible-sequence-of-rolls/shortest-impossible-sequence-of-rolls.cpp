class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> s;
        int ans = 1;

        for (int num : rolls) {
            s.insert(num);

            if (s.size() == k) {
                ans++;
                s.clear();
            }
        }

        return ans;
    }
};