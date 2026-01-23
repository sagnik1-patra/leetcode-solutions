class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);

        // Count frequency of arr1
        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> result;

        // Place elements according to arr2 order
        for (int x : arr2) {
            while (freq[x]-- > 0) {
                result.push_back(x);
            }
        }

        // Place remaining elements in ascending order
        for (int i = 0; i <= 1000; i++) {
            while (freq[i]-- > 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};
