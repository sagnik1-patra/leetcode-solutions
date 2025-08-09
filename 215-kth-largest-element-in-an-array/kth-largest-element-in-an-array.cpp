class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) { // for kth largest
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }

    int quickselect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        int pivotIndex = partition(nums, left, right);
        
        if (pivotIndex == k) return nums[pivotIndex];
        else if (pivotIndex < k) return quickselect(nums, pivotIndex + 1, right, k);
        else return quickselect(nums, left, pivotIndex - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }
};
