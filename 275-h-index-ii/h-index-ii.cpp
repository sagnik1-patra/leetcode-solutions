class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1, firstIdx = n; // first index where citations[i] >= n - i
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int papersWithAtLeastMid = n - mid;
            if (citations[mid] >= papersWithAtLeastMid) {
                firstIdx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - firstIdx; // 0 if never found; else n - index
    }
};
