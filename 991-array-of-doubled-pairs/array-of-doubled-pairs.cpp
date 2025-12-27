class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;

        // sort by absolute value
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int x : arr) {
            if (freq[x] == 0) continue;

            if (freq[2 * x] < freq[x])
                return false;

            freq[2 * x] -= freq[x];
            freq[x] = 0;
        }

        return true;
    }
};
