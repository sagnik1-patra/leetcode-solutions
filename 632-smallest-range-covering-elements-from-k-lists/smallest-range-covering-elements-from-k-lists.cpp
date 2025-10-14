class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using T = tuple<int, int, int>; // (value, list index, element index)
        priority_queue<T, vector<T>, greater<T>> minHeap;

        int currentMax = INT_MIN;
        int rangeStart = 0, rangeEnd = INT_MAX;

        // Initialize heap with first element of each list
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.emplace(nums[i][0], i, 0);
            currentMax = max(currentMax, nums[i][0]);
        }

        while (true) {
            auto [val, listIdx, elemIdx] = minHeap.top();
            minHeap.pop();

            // Update range if it's smaller or equal but with smaller start
            if (currentMax - val < rangeEnd - rangeStart) {
                rangeStart = val;
                rangeEnd = currentMax;
            }

            // Move forward in the list
            if (elemIdx + 1 == nums[listIdx].size()) break;
            int nextVal = nums[listIdx][elemIdx + 1];
            minHeap.emplace(nextVal, listIdx, elemIdx + 1);
            currentMax = max(currentMax, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};
