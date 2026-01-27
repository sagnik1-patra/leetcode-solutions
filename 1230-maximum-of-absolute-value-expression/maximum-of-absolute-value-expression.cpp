class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int ans = 0;

        int max1 = INT_MIN, min1 = INT_MAX;
        int max2 = INT_MIN, min2 = INT_MAX;
        int max3 = INT_MIN, min3 = INT_MAX;
        int max4 = INT_MIN, min4 = INT_MAX;

        for (int i = 0; i < n; i++) {
            int a = arr1[i];
            int b = arr2[i];

            max1 = max(max1, a + b + i);
            min1 = min(min1, a + b + i);

            max2 = max(max2, a + b - i);
            min2 = min(min2, a + b - i);

            max3 = max(max3, a - b + i);
            min3 = min(min3, a - b + i);

            max4 = max(max4, a - b - i);
            min4 = min(min4, a - b - i);
        }

        ans = max({
            max1 - min1,
            max2 - min2,
            max3 - min3,
            max4 - min4
        });

        return ans;
    }
};
