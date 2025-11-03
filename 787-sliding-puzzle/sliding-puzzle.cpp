class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto& row : board)
            for (int num : row)
                start += to_string(num);
        
        string target = "123450";
        if (start == target) return 0;

        vector<vector<int>> moves = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [state, steps] = q.front();
            q.pop();

            int zero = state.find('0');
            for (int nxt : moves[zero]) {
                string newState = state;
                swap(newState[zero], newState[nxt]);
                if (visited.count(newState)) continue;
                if (newState == target) return steps + 1;
                visited.insert(newState);
                q.push({newState, steps + 1});
            }
        }

        return -1;
    }
};
