class Solution {
public:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
    };

    void insert(TrieNode* root, int num) {
        TrieNode* node = root;

        for (int bit = 30; bit >= 0; bit--) {
            int b = (num >> bit) & 1;

            if (!node->child[b])
                node->child[b] = new TrieNode();

            node = node->child[b];
        }
    }

    int getMaxXor(TrieNode* root, int x) {
        TrieNode* node = root;
        int ans = 0;

        for (int bit = 30; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            int opposite = 1 - b;

            if (node->child[opposite]) {
                ans |= (1 << bit);
                node = node->child[opposite];
            } else {
                node = node->child[b];
            }
        }

        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }

        sort(q.begin(), q.end());

        vector<int> answer(queries.size(), -1);

        TrieNode* root = new TrieNode();

        int j = 0;

        for (auto& query : q) {
            int m = query[0];
            int x = query[1];
            int index = query[2];

            while (j < nums.size() && nums[j] <= m) {
                insert(root, nums[j]);
                j++;
            }

            if (j > 0) {
                answer[index] = getMaxXor(root, x);
            }
        }

        return answer;
    }
};