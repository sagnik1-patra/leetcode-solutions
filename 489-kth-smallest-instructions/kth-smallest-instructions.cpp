class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n - r)
            r = n - r;

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }

        return res;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0]; // number of V
        int h = destination[1]; // number of H

        string ans = "";

        while (h > 0 || v > 0) {

            // No H left
            if (h == 0) {
                ans += 'V';
                v--;
                continue;
            }

            // No V left
            if (v == 0) {
                ans += 'H';
                h--;
                continue;
            }

            /*
                If we place H now, remaining characters are:
                h - 1 H's and v V's

                Number of strings starting with H:
                C(h + v - 1, v)
            */
            long long countStartingWithH = nCr(h + v - 1, v);

            if (k <= countStartingWithH) {
                ans += 'H';
                h--;
            }
            else {
                ans += 'V';
                v--;

                // Skip all strings starting with H
                k -= countStartingWithH;
            }
        }

        return ans;
    }
};