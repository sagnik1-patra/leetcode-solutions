class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // empty constructor
    }
    
    int ping(int t) {
        q.push(t);

        // Remove requests older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};
