class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        
        int maxDur = releaseTimes[0];
        char ans = keysPressed[0];
        
        for (int i = 1; i < n; i++) {
            int dur = releaseTimes[i] - releaseTimes[i - 1];
            
            if (dur > maxDur) {
                maxDur = dur;
                ans = keysPressed[i];
            } 
            else if (dur == maxDur && keysPressed[i] > ans) {
                ans = keysPressed[i];
            }
        }
        
        return ans;
    }
};