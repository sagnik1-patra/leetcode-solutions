class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        vector<int> counts;

        for (auto it : freq) {
            counts.push_back(it.second);
        }

        sort(counts.begin(), counts.end());

        int unique = counts.size();

        for (int count : counts) {
            if (k >= count) {
                k -= count;
                unique--;
            } else {
                break;
            }
        }

        return unique;
    }
};