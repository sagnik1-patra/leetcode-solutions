class Solution {
public:
    bool isSquare(int x) {
        int r = (int)std::sqrt(x);
        return r * r == x;
    }
    
    int numSquares(int n) {
        if (isSquare(n)) return 1;

        // Reduce n by removing factors of 4 (Lagrange + Legendre optimizations)
        while (n % 4 == 0) n /= 4;
        // If n ≡ 7 (mod 8), then the answer is 4
        if (n % 8 == 7) return 4;

        // Check if the answer is 2 (n = a^2 + b^2)
        for (int a = 1; a * a <= n; ++a) {
            if (isSquare(n - a * a)) return 2;
        }
        // Otherwise it's 3 (by Lagrange's four-square theorem)
        return 3;
    }
};
