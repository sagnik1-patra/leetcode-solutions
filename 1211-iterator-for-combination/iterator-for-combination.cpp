class CombinationIterator {
private:
    vector<string> combs;
    int index = 0;

    void generate(string &chars, int len, int start, string curr) {
        if (curr.size() == len) {
            combs.push_back(curr);
            return;
        }

        for (int i = start; i < chars.size(); i++) {
            generate(chars, len, i + 1, curr + chars[i]);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        generate(characters, combinationLength, 0, "");
    }
    
    string next() {
        return combs[index++];
    }
    
    bool hasNext() {
        return index < combs.size();
    }
};