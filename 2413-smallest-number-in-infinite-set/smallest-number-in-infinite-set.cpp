class SmallestInfiniteSet {
private:
    int curr;
    set<int> s;

public:
    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!s.empty()) {
            int ans = *s.begin();
            s.erase(s.begin());
            return ans;
        }

        return curr++;
    }

    void addBack(int num) {
        if (num < curr) {
            s.insert(num);
        }
    }
};