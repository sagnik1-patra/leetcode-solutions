
class Solution {
public:
    vector<int> smallestMissingValueSubtree(
        vector<int>& parents,
        vector<int>& nums
    ) {
        int n = nums.size();

        vector<vector<int>> children(n);
        vector<int> ans(n, 1);
        vector<bool> visited(n, false);
        vector<bool> seen(n + 2, false);

        int node = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                node = i;
                break;
            }
        }

        if (node == -1)
            return ans;

        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }

        int missing = 1;

        while (node != -1) {
            stack<int> st;
            st.push(node);

            while (!st.empty()) {
                int u = st.top();
                st.pop();

                if (visited[u])
                    continue;

                visited[u] = true;

                if (nums[u] <= n + 1)
                    seen[nums[u]] = true;

                for (int child : children[u]) {
                    if (!visited[child])
                        st.push(child);
                }
            }

            while (missing <= n + 1 && seen[missing]) {
                missing++;
            }

            ans[node] = missing;
            node = parents[node];
        }

        return ans;
    }
};
