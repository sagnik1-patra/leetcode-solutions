class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size(), i = 0, best = 0;
        // len[d] = path length up to depth d (directories only), with trailing '/'
        vector<int> len(1, 0); // depth 0 has length 0

        while (i < n) {
            // 1) count depth (number of '\t')
            int depth = 0;
            while (i < n && input[i] == '\t') { ++depth; ++i; }

            // ensure len array has room
            if ((int)len.size() <= depth) len.resize(depth + 1, 0);

            // 2) read name until '\n' or end
            int start = i;
            bool isFile = false;
            while (i < n && input[i] != '\n') {
                if (input[i] == '.') isFile = true;
                ++i;
            }
            int nameLen = i - start;
            if (i < n && input[i] == '\n') ++i; // skip newline

            if (isFile) {
                // total path length: len[depth] (already has trailing '/')
                // plus this file's name length
                best = max(best, len[depth] + nameLen);
            } else {
                // directory: prepare len for next depth
                int total = len[depth] + nameLen + 1; // add '/'
                if ((int)len.size() <= depth + 1) len.resize(depth + 2, 0);
                len[depth + 1] = total;
            }
        }
        return best;
    }
};
