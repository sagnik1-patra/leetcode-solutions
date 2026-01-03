class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Sort clips by start time
        sort(clips.begin(), clips.end());

        int currEnd = 0;     // current covered end
        int farthest = 0;    // farthest reachable end
        int count = 0;
        int i = 0;
        int n = clips.size();

        while (currEnd < time) {
            // Extend coverage as far as possible
            while (i < n && clips[i][0] <= currEnd) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            // Cannot extend coverage
            if (farthest == currEnd)
                return -1;

            count++;
            currEnd = farthest;
        }

        return count;
    }
};
