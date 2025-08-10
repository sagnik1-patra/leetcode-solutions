class MyStack {
private:
    queue<int> q1, q2; // two queues

public:
    MyStack() {}

    void push(int x) {
        // Push into q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 so q1 always has the stack order
        swap(q1, q2);
    }

    int pop() {
        int topElem = q1.front();
        q1.pop();
        return topElem;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};