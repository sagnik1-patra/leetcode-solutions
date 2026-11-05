
class SORTracker {
    using P = pair<int, string>;

    // Worst among selected locations at top
    priority_queue<P> left;

    // Best among remaining locations at top
    priority_queue<P, vector<P>, greater<P>> right;

public:
    SORTracker() {}

    void add(string name, int score) {
        P p = {-score, name};

        left.push(p);

        right.push(left.top());
        left.pop();
    }

    string get() {
        left.push(right.top());
        right.pop();

        return left.top().second;
    }
};
