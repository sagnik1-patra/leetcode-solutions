class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id, int level) {
        
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        // BFS setup
        q.push(id);
        visited[id] = true;
        int currLevel = 0;
        
        // BFS till desired level
        while (!q.empty() && currLevel < level) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int person = q.front(); q.pop();
                
                for (int f : friends[person]) {
                    if (!visited[f]) {
                        visited[f] = true;
                        q.push(f);
                    }
                }
            }
            currLevel++;
        }
        
        // Count video frequencies
        unordered_map<string, int> freq;
        
        while (!q.empty()) {
            int person = q.front(); q.pop();
            for (string &video : watchedVideos[person]) {
                freq[video]++;
            }
        }
        
        // Move to vector for sorting
        vector<pair<string, int>> videos(freq.begin(), freq.end());
        
        sort(videos.begin(), videos.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first < b.first; // lexicographical
            return a.second < b.second; // frequency
        });
        
        // Extract result
        vector<string> result;
        for (auto &p : videos) {
            result.push_back(p.first);
        }
        
        return result;
    }
};