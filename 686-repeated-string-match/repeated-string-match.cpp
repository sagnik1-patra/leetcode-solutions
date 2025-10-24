class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;
        
        // Keep appending 'a' until its length >= b's length
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }
        
        // Case 1: check if 'b' is substring of current repeated string
        if (repeated.find(b) != string::npos)
            return count;
        
        // Case 2: check one more repetition (in case b overlaps boundary)
        repeated += a;
        if (repeated.find(b) != string::npos)
            return count + 1;
        
        // Case 3: impossible
        return -1;
    }
};