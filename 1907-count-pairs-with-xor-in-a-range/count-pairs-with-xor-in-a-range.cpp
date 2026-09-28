class Solution {
    struct Node {
        Node* child[2];
        int count;

        Node() {
            child[0] = child[1] = nullptr;
            count = 0;
        }
    };

    Node* root;

    void insert(int num) {
        Node* node = root;

        for (int bit = 15; bit >= 0; bit--) {
            int b = (num >> bit) & 1;

            if (!node->child[b])
                node->child[b] = new Node();

            node = node->child[b];
            node->count++;
        }
    }

    // Count previously inserted numbers x where:
    // (num XOR x) < limit
    int countLess(int num, int limit) {
        Node* node = root;
        int result = 0;

        for (int bit = 15; bit >= 0 && node; bit--) {

            int numBit = (num >> bit) & 1;
            int limitBit = (limit >> bit) & 1;

            if (limitBit == 1) {
                // Make XOR bit 0.
                // This immediately makes this prefix smaller
                // than the limit prefix.
                if (node->child[numBit])
                    result += node->child[numBit]->count;

                // To remain equal so far, XOR bit must be 1.
                node = node->child[numBit ^ 1];
            }
            else {
                // limit bit = 0
                // XOR must also be 0 to remain smaller/equal.
                node = node->child[numBit];
            }
        }

        return result;
    }

    int countPairs(vector<int>& nums, int limit) {
        root = new Node();

        int answer = 0;

        for (int num : nums) {
            answer += countLess(num, limit);
            insert(num);
        }

        return answer;
    }

public:
    int countPairs(vector<int>& nums, int low, int high) {

        return countPairs(nums, high + 1)
             - countPairs(nums, low);
    }
};