class MedianFinder {
public:
    // max-heap for lower half, min-heap for upper half
    std::priority_queue<int> lo;
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi;

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: push to lo (lower half)
        lo.push(num);
        // Step 2: move the largest of lo to hi to maintain order: lo <= hi
        hi.push(lo.top());
        lo.pop();
        // Step 3: rebalance sizes so that lo has the same size as hi (or one more)
        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};
