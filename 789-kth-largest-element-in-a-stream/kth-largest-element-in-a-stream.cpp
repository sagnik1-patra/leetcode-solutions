class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top(); // kth largest
    }
};
