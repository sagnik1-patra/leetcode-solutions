class Solution {
public:
    int bulbSwitch(int n) {
        // A bulb ends up on iff it's toggled an odd number of times,
        // which happens only for perfect-square indices (they have odd # of divisors).
        // Count of perfect squares ≤ n is floor(sqrt(n)).
        return (int)std::sqrt(n);
    }
};
