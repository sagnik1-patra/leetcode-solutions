
class Solution {
public:
    struct TrieNode {
        int child[2] = {-1, -1};
        int count = 0;
    };

    vector<TrieNode> trie;

    void insert(int num, int delta) {
        int node = 0;
        trie[node].count += delta;

        for (int i = 17; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[bit];
            trie[node].count += delta;
        }
    }

    int getMaxXor(int num) {
        int node = 0;
        int ans = 0;

        for (int i = 17; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = bit ^ 1;

            int next = trie[node].child[opposite];

            if (next != -1 && trie[next].count > 0) {
                ans |= (1 << i);
                node = next;
            } else {
                node = trie[node].child[bit];
            }
        }

        return ans;
    }

    vector<int> maxGeneticDifference(
        vector<int>& parents,
        vector<vector<int>>& queries
    ) {
        int n = parents.size();
        int root = -1;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                root = i;
            } else {
                adj[parents[i]].push_back(i);
            }
        }

        vector<vector<pair<int, int>>> q(n);

        for (int i = 0; i < queries.size(); i++) {
            int node = queries[i][0];
            int val = queries[i][1];

            q[node].push_back({val, i});
        }

        vector<int> ans(queries.size());

        trie.clear();
        trie.emplace_back();

        // Iterative DFS avoids recursion stack overflow
        stack<pair<int, bool>> st;
        st.push({root, false});

        while (!st.empty()) {
            auto [node, exiting] = st.top();
            st.pop();

            if (exiting) {
                insert(node, -1);
                continue;
            }

            // Add current node to the Trie
            insert(node, 1);

            // Answer queries for this node
            for (auto [val, idx] : q[node]) {
                ans[idx] = getMaxXor(val);
            }

            // Remove node after processing its subtree
            st.push({node, true});

            for (int child : adj[node]) {
                st.push({child, false});
            }
        }

        return ans;
    }
};
