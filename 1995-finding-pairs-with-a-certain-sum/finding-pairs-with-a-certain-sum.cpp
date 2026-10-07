class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;

    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        // Store frequency of every value in nums2
        for (int x : nums2) {
            freq2[x]++;
        }
    }

    void add(int index, int val) {
        // Remove old value from frequency map
        freq2[nums2[index]]--;

        // Update nums2
        nums2[index] += val;

        // Add new value to frequency map
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int result = 0;

        for (int x : nums1) {
            int needed = tot - x;

            if (freq2.count(needed)) {
                result += freq2[needed];
            }
        }

        return result;
    }
};