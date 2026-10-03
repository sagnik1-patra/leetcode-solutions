class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> present(mx + 1, false);

        for (int x : nums) {
            present[x] = true;
        }

        int answer = 0;

        // Try every possible GCD
        for (int g = 1; g <= mx; g++) {

            int currentGCD = 0;

            // Only multiples of g can participate
            for (int multiple = g; multiple <= mx; multiple += g) {

                if (present[multiple]) {
                    currentGCD = gcd(currentGCD, multiple);

                    // We found a subsequence whose GCD is g
                    if (currentGCD == g) {
                        answer++;
                        break;
                    }
                }
            }
        }

        return answer;
    }
};