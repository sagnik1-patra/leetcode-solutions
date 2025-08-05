class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle negative numbers
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Convert to long to avoid overflow
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // Add the integer part
        result += to_string(num / den);
        num %= den;
        
        if (num == 0) return result;
        
        result += ".";
        unordered_map<long long, int> seen;  // Map to store previously seen remainders
        
        while (num != 0) {
            if (seen.count(num)) {
                result.insert(seen[num], "(");
                result += ")";
                break;
            }
            seen[num] = result.size();
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }
        
        return result;
    }
};
