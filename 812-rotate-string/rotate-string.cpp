class Solution {
public:
    bool rotateString(string s, string goal) {
        // Both strings must be of equal length
        if (s.size() != goal.size()) return false;

        // If goal is a substring of s + s, rotation is possible
        return (s + s).find(goal) != string::npos;
    }
};