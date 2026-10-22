
class DetectSquares {
public:
    map<pair<int, int>, int> points;

    DetectSquares() {
    }

    void add(vector<int> point) {
        points[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto& p : points) {
            int x2 = p.first.first;
            int y2 = p.first.second;
            int freq = p.second;

            if (abs(x2 - x) == abs(y2 - y) && x2 != x) {
                ans += freq *
                       points[{x, y2}] *
                       points[{x2, y}];
            }
        }

        return ans;
    }
};
