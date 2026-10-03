class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        unordered_map<int, unordered_set<int>> activity;

        // Store unique active minutes for each user
        for (auto& log : logs) {
            int id = log[0];
            int time = log[1];

            activity[id].insert(time);
        }

        vector<int> answer(k, 0);

        // Count users according to their UAM
        for (auto& user : activity) {
            int uam = user.second.size();

            answer[uam - 1]++;
        }

        return answer;
    }
};