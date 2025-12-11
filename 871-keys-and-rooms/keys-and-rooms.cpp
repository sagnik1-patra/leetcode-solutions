class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        stack<int> st;

        st.push(0);
        visited[0] = true;

        while (!st.empty()) {
            int room = st.top();
            st.pop();

            // Collect all keys in this room
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    st.push(key);
                }
            }
        }

        // Check if all rooms were visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};
