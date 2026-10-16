
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> temp;

        for (int x : obstacles) {
            int pos = upper_bound(temp.begin(), temp.end(), x) - temp.begin();

            if (pos == temp.size()) {
                temp.push_back(x);
            } else {
                temp[pos] = x;
            }

            ans.push_back(pos + 1);
        }

        return ans;
    }
};
