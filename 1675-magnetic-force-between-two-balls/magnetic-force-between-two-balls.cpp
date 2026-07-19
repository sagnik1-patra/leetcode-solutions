class Solution {
public:
    bool canPlace(vector<int>& pos, int m, int dist) {
        int count = 1; // first ball
        int last = pos[0];
        
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - last >= dist) {
                count++;
                last = pos[i];
            }
            if (count >= m) return true;
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 1;
        int right = position.back() - position[0];
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlace(position, m, mid)) {
                ans = mid;
                left = mid + 1; // try bigger
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};