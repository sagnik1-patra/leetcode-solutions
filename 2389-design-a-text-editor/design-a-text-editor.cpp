class TextEditor {
private:
    string left, right;

    string getLast10() {
        int len = left.size();
        return left.substr(max(0, len - 10));
    }

public:
    TextEditor() {
        left = "";
        right = "";
    }

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int deleted = min(k, (int)left.size());

        left.resize(left.size() - deleted);

        return deleted;
    }

    string cursorLeft(int k) {
        while (k > 0 && !left.empty()) {
            right.push_back(left.back());
            left.pop_back();
            k--;
        }

        return getLast10();
    }

    string cursorRight(int k) {
        while (k > 0 && !right.empty()) {
            left.push_back(right.back());
            right.pop_back();
            k--;
        }

        return getLast10();
    }
};