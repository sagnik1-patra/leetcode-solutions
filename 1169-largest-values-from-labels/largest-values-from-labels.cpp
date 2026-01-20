class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> items;

        for (int i = 0; i < n; i++) {
            items.push_back({values[i], labels[i]});
        }

        // Sort by value descending
        sort(items.begin(), items.end(), greater<>());

        unordered_map<int, int> labelCount;
        int sum = 0, taken = 0;

        for (auto& item : items) {
            if (taken == numWanted) break;

            int value = item.first;
            int label = item.second;

            if (labelCount[label] < useLimit) {
                sum += value;
                labelCount[label]++;
                taken++;
            }
        }

        return sum;
    }
};
