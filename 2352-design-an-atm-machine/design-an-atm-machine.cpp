class ATM {
public:
    long long notes[5] = {0};
    int value[5] = {20, 50, 100, 200, 500};

    ATM() {

    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            notes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);

        for (int i = 4; i >= 0; i--) {
            int count = min((long long)(amount / value[i]), notes[i]);

            ans[i] = count;
            amount -= count * value[i];
        }

        if (amount != 0) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            notes[i] -= ans[i];
        }

        return ans;
    }
};