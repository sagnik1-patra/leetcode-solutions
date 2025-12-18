class RLEIterator {
public:
    vector<long long> enc;
    int idx;  // points to count position

    RLEIterator(vector<int>& encoding) {
        idx = 0;
        enc.assign(encoding.begin(), encoding.end());
    }

    int next(int n) {
        while (idx < enc.size() && n > 0) {
            if (enc[idx] >= n) {
                enc[idx] -= n;
                return enc[idx + 1];
            } else {
                n -= enc[idx];
                idx += 2;
            }
        }
        return -1;
    }
};
