class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        
        // Step 1: compute indegree
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1) return false;
            }
        }
        
        // Step 2: find root
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) return false; // multiple roots
                root = i;
            }
        }
        
        if (root == -1) return false; // no root
        
        // Step 3: check connectivity (DFS)
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(root);
        
        int count = 0;
        
        while (!st.empty()) {
            int node = st.top(); st.pop();
            
            if (visited[node]) return false; // cycle
            
            visited[node] = true;
            count++;
            
            if (leftChild[node] != -1) st.push(leftChild[node]);
            if (rightChild[node] != -1) st.push(rightChild[node]);
        }
        
        return count == n;
    }
};