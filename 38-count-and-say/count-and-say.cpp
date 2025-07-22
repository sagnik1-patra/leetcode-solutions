class Solution {
public:
    string countAndSay(int n) {
        string result = "1"; // Base case: countAndSay(1)

        for (int i = 2; i <= n; ++i) {
            string current = "";
            int count = 1;
            char prev = result[0];
            
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == prev) {
                    ++count; // Same digit, increment count
                } else {
                    current += to_string(count) + prev; // Append count and digit
                    prev = result[j]; // Move to next digit
                    count = 1; // Reset count
                }
            }
            current += to_string(count) + prev; // Append last group
            result = current; // Update result
        }

        return result;
    }
};
