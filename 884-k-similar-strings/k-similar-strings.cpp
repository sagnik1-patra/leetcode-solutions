class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s1);
        visited.insert(s1);

        int swaps = 0;

        while (!q.empty()) {
            int size = q.size();
            swaps++;

            while (size--) {
                string cur = q.front();
                q.pop();

                // find first mismatch
                int i = 0;
                while (cur[i] == s2[i]) i++;

                for (int j = i + 1; j < cur.size(); j++) {
                    // only useful swaps
                    if (cur[j] == s2[i] && cur[j] != s2[j]) {
                        string next = cur;
                        swap(next[i], next[j]);

                        if (next == s2)
                            return swaps;

                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }

        return swaps;
    }
};
