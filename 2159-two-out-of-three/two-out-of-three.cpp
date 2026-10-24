
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());
        set<int> c(nums3.begin(), nums3.end());

        vector<int> result;

        for (int x = 1; x <= 100; x++) {
            int count = 0;

            if (a.count(x)) count++;
            if (b.count(x)) count++;
            if (c.count(x)) count++;

            if (count >= 2) {
                result.push_back(x);
            }
        }

        return result;
    }
};
