class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;          // digit length of numbers in current block
        long long count = 9;        // how many numbers in current block
        long long start = 1;        // first number in current block
        long long N = n;

        // Skip full blocks until the block that contains the answer
        while (N > len * count) {
            N -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        // Find the exact number containing the N-th digit
        long long idx = (N - 1) / len;        // zero-based index of number in the block
        long long num = start + idx;

        // Find the digit within that number
        int digitIdx = (int)((N - 1) % len);  // zero-based index within num
        // Extract digit at digitIdx
        // Convert only once; len ≤ 10 for constraints, safe
        string s = to_string(num);
        return s[digitIdx] - '0';
    }
};
