class Solution {
    vector<int> original;
    mt19937 rng; // random generator

public:
    Solution(vector<int>& nums) : original(nums), rng(random_device{}()) {}

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> arr = original;
        for (int i = arr.size() - 1; i > 0; --i) {
            uniform_int_distribution<int> dist(0, i);
            int j = dist(rng);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};
