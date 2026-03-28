class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group people by group size
        for (int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> result;

        // Step 2: split into groups
        for (auto &p : mp) {
            int size = p.first;
            vector<int> &people = p.second;

            for (int i = 0; i < people.size(); i += size) {
                vector<int> group;
                for (int j = i; j < i + size; j++) {
                    group.push_back(people[j]);
                }
                result.push_back(group);
            }
        }

        return result;
    }
};