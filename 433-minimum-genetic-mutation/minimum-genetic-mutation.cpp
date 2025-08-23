class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(endGene)) return -1;  // end must be in bank

        queue<string> q;
        unordered_set<string> vis;
        q.push(startGene);
        vis.insert(startGene);

        const string letters = "ACGT";
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front(); q.pop();
                if (cur == endGene) return steps;

                for (int i = 0; i < 8; ++i) {
                    char old = cur[i];
                    for (char ch : letters) {
                        if (ch == old) continue;
                        cur[i] = ch;
                        if (dict.count(cur) && !vis.count(cur)) {
                            vis.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = old; // restore
                }
            }
            ++steps;
        }
        return -1;
    }
};
