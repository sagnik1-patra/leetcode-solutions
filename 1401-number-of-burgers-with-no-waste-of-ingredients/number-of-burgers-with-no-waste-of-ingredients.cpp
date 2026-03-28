class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // Check basic feasibility
        if (tomatoSlices < 2 * cheeseSlices || 
            tomatoSlices > 4 * cheeseSlices) {
            return {};
        }

        // Must be even
        if ((tomatoSlices - 2 * cheeseSlices) % 2 != 0) {
            return {};
        }

        int jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
        int small = cheeseSlices - jumbo;

        if (jumbo < 0 || small < 0) return {};

        return {jumbo, small};
    }
};