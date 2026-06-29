class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1, 1};

        while (fib.back() < k) {
            int n = fib.size();
            fib.push_back(fib[n - 1] + fib[n - 2]);
        }

        int count = 0;

        for (int i = fib.size() - 1; i >= 0 && k > 0; i--) {
            if (fib[i] <= k) {
                k -= fib[i];
                count++;
            }
        }

        return count;
    }
};