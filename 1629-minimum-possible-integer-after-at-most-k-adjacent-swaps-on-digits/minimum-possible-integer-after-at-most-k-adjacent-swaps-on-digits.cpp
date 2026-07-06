class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();

        vector<queue<int>> pos(10);

        for (int i = 0; i < n; i++) {
            pos[num[i] - '0'].push(i + 1);
        }

        Fenwick fw(n);
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int d = 0; d <= 9; d++) {
                if (pos[d].empty()) continue;

                int originalPos = pos[d].front();

                int removedBefore = fw.sum(originalPos);
                int currentPos = originalPos - removedBefore;

                int cost = currentPos - 1;

                if (cost <= k) {
                    k -= cost;
                    ans += char(d + '0');

                    fw.add(originalPos, 1);
                    pos[d].pop();

                    break;
                }
            }
        }

        return ans;
    }
};