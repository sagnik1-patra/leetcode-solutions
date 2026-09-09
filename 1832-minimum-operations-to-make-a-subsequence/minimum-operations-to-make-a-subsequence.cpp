class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> pos;

        for (int i = 0; i < target.size(); i++) {
            pos[target[i]] = i;
        }

        vector<int> lis;

        for (int x : arr) {
            if (pos.count(x)) {
                int index = pos[x];

                auto it = lower_bound(lis.begin(), lis.end(), index);

                if (it == lis.end())
                    lis.push_back(index);
                else
                    *it = index;
            }
        }

        return target.size() - lis.size();
    }
};