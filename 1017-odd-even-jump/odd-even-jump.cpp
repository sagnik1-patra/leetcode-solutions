class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> oddNext(n, -1), evenNext(n, -1);

        // ---------- ODD JUMPS ----------
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] < arr[b];
        });

        stack<int> st;
        for (int i : idx) {
            while (!st.empty() && i > st.top()) {
                oddNext[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // ---------- EVEN JUMPS ----------
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] > arr[b];
        });

        while (!st.empty()) st.pop();

        for (int i : idx) {
            while (!st.empty() && i > st.top()) {
                evenNext[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // ---------- DP ----------
        vector<bool> oddGood(n, false), evenGood(n, false);
        oddGood[n - 1] = evenGood[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            if (oddNext[i] != -1)
                oddGood[i] = evenGood[oddNext[i]];
            if (evenNext[i] != -1)
                evenGood[i] = oddGood[evenNext[i]];
        }

        // ---------- COUNT ----------
        int count = 0;
        for (bool ok : oddGood) {
            if (ok) count++;
        }

        return count;
    }
};
