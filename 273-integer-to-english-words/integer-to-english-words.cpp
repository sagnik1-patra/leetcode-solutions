class Solution {
public:
    vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                              "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                              "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                          "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string words = "";
        int idx = 0;

        while (num > 0) {
            int part = num % 1000;
            if (part != 0) {
                string seg = helper(part);
                if (!thousands[idx].empty()) seg += " " + thousands[idx];
                if (words.empty()) words = seg;
                else words = seg + " " + words;
            }
            num /= 1000;
            ++idx;
        }
        return words;
    }

private:
    // helper returns the words for 1..999 WITHOUT any leading/trailing spaces
    string helper(int num) {
        if (num == 0) return "";
        if (num < 20) return below20[num];
        if (num < 100) {
            string res = tens[num / 10];
            if (num % 10) res += " " + below20[num % 10];
            return res;
        }
        // num >= 100
        string res = below20[num / 100] + " Hundred";
        if (num % 100) res += " " + helper(num % 100);
        return res;
    }
};
