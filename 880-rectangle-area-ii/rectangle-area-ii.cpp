class Solution {
public:
    static const int MOD = 1e9 + 7;

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> ys;

        // Collect all y-coordinates
        for (auto &r : rectangles) {
            ys.push_back(r[1]);
            ys.push_back(r[3]);
        }

        // Coordinate compression
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int m = ys.size();

        // length[i] = (covered length among ys[i] to ys[i+1])
        vector<long long> coverCount(4 * m), covered(4 * m);

        // Update segment tree for y-interval [l, r)
        function<void(int,int,int,int,int,int)> update = [&](int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                coverCount[node] += val;
            } else {
                int mid = (l + r) / 2;
                update(node*2, l, mid, ql, qr, val);
                update(node*2+1, mid, r, ql, qr, val);
            }

            if (coverCount[node] > 0) {
                covered[node] = ys[r] - ys[l];
            } else {
                covered[node] = (l + 1 == r) ? 0 : covered[node*2] + covered[node*2+1];
            }
        };

        // Build sweep line events
        // event: (x, type=+1 add / -1 remove, y1, y2)
        vector<array<long long,4>> events;
        for (auto &r : rectangles) {
            long long x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];

            int l = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
            int rpos = lower_bound(ys.begin(), ys.end(), y2) - ys.begin();

            events.push_back({x1, +1, l, rpos});
            events.push_back({x2, -1, l, rpos});
        }

        sort(events.begin(), events.end()); // sort by x

        long long prevX = events[0][0];
        long long area = 0;

        for (auto &e : events) {
            long long x = e[0], type = e[1], l = e[2], rpos = e[3];

            long long width = x - prevX;
            long long height = covered[1];   // total covered Y-length
            area = (area + width % MOD * height % MOD) % MOD;

            // Apply current event
            update(1, 0, m - 1, l, rpos, type);

            prevX = x;
        }

        return area % MOD;
    }
};
