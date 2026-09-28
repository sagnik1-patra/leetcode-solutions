class Solution {
public:
    bool checkOnesSegment(string s) {
        // If "01" appears, a new segment of 1s starts
        // after the first segment has already ended.
        return s.find("01") == string::npos;
    }
};