class Solution {
public:
    int minInsertions(string s) {
        int need = 0;        // how many ')' needed
        int insertions = 0;
        
        for (char c : s) {
            if (c == '(') {
                need += 2;
                
                if (need % 2 == 1) {
                    // fix odd → insert one ')'
                    insertions++;
                    need--;
                }
            } else { // ')'
                need--;
                
                if (need < 0) {
                    // need a '('
                    insertions++;
                    need = 1;
                }
            }
        }
        
        return insertions + need;
    }
};