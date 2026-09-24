class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int largest = max({a, b, c});
        int others = sum - largest;

        // Either we use half of all stones,
        // or the two smaller piles get exhausted first.
        return min(sum / 2, others);
    }
};