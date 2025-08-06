class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Custom sort: for two strings a and b, compare a+b and b+a
        sort(strNums.begin(), strNums.end(), [](string& a, string& b) {
            return a + b > b + a;
        });

        // If the highest number is "0", the entire number is "0"
        if (strNums[0] == "0") return "0";

        // Concatenate all strings
        string result;
        for (string& s : strNums) {
            result += s;
        }

        return result;
    }
};
