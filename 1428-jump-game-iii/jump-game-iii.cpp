class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // If we reach 0
            if (arr[i] == 0) return true;

            // Forward jump
            int forward = i + arr[i];
            if (forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }

            // Backward jump
            int backward = i - arr[i];
            if (backward >= 0 && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};