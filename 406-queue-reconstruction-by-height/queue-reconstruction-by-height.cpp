class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b){
                 if (a[0] != b[0]) return a[0] > b[0]; // taller first
                 return a[1] < b[1];                  // smaller k first
             });

        vector<vector<int>> ans;
        ans.reserve(people.size());
        for (auto& p : people) {
            ans.insert(ans.begin() + p[1], p); // insert at index k
        }
        return ans;
    }
};
