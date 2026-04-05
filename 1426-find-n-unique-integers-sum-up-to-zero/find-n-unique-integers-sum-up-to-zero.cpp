class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        int num = 1;

        // Add pairs
        while (result.size() < n - (n % 2)) {
            result.push_back(num);
            result.push_back(-num);
            num++;
        }

        // If n is odd, add 0
        if (n % 2 == 1) {
            result.push_back(0);
        }

        return result;
    }
};