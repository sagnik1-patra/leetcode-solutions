class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // Ugly numbers must be positive
        
        // Keep dividing by 2, 3, or 5 if possible
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        
        // If we end up with 1, it's an ugly number
        return n == 1;
    }
};