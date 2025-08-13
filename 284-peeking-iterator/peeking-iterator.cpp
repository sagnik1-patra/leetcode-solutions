// Below is the Iterator interface already defined by LeetCode.
// class Iterator {
//     struct Data;
//     Data* data;
// public:
//     Iterator(const vector<int>& nums);
//     Iterator(const Iterator& iter);
//     virtual ~Iterator();
//     // Returns the next element in the iteration.
//     int next();
//     // Returns true if the iteration has more elements.
//     bool hasNext() const;
// };

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const Iterator& iter) : Iterator(iter), hasPeek(false), peekVal(0) {}

    // Returns the next element without advancing the iterator.
    int peek() {
        if (!hasPeek) {
            peekVal = Iterator::next();
            hasPeek = true;
        }
        return peekVal;
    }

    // Return next and advance.
    int next() {
        if (hasPeek) {
            hasPeek = false;
            return peekVal;
        }
        return Iterator::next();
    }

    // Are there elements left?
    bool hasNext() const {
        return hasPeek || Iterator::hasNext();
    }

private:
    bool hasPeek;
    int  peekVal;
};
