class FreqStack {
public:
    unordered_map<int, int> freq;                 // value -> frequency
    unordered_map<int, stack<int>> group;         // frequency -> stack of values
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        int f = ++freq[val];
        maxFreq = max(maxFreq, f);
        group[f].push(val);
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
