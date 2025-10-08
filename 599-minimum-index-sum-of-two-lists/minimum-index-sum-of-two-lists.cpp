class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        for (int i = 0; i < list1.size(); i++)
            indexMap[list1[i]] = i;

        int minSum = INT_MAX;
        vector<string> result;

        for (int j = 0; j < list2.size(); j++) {
            if (indexMap.count(list2[j])) {
                int sum = j + indexMap[list2[j]];
                if (sum < minSum) {
                    minSum = sum;
                    result = {list2[j]};
                } else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};