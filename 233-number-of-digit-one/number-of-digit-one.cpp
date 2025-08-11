class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        long long divider = 1;
        
        while (divider <= n) {
            long long left = n / (divider * 10);
            long long current = (n / divider) % 10;
            long long right = n % divider;
            
            if (current > 1) {
                count += (left + 1) * divider;
            } else if (current == 1) {
                count += left * divider + right + 1;
            } else {
                count += left * divider;
            }
            
            divider *= 10;
        }
        
        return (int)count;
    }
};
