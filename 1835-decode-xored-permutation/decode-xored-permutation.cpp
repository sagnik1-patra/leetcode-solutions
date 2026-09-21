class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;

        int totalXor = 0;

        // XOR of all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            totalXor ^= i;
        }

        int oddXor = 0;

        // XOR of encoded[1], encoded[3], ...
        // gives perm[1] ^ perm[2] ^ ... ^ perm[n-1]
        for (int i = 1; i < encoded.size(); i += 2) {
            oddXor ^= encoded[i];
        }

        // Find the first element
        int first = totalXor ^ oddXor;

        vector<int> perm(n);

        perm[0] = first;

        // Reconstruct remaining elements
        for (int i = 0; i < encoded.size(); i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }

        return perm;
    }
};