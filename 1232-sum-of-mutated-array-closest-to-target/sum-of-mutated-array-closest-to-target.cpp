class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int left = 0, right = *max_element(arr.begin(), arr.end());
        
        int answer = right;
        int minDiff = INT_MAX;

        while (left <= right) {
            int mid = (left + right) / 2;

            int sum = 0;
            for (int num : arr) {
                sum += min(num, mid);
            }

            int diff = abs(sum - target);

            // Update best answer
            if (diff < minDiff || (diff == minDiff && mid < answer)) {
                minDiff = diff;
                answer = mid;
            }

            // Binary search decision
            if (sum < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};