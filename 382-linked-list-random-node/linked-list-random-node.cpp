/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <random>

class Solution {
    ListNode* head;
    std::mt19937 rng;  // good-quality RNG
public:
    Solution(ListNode* head) : head(head), rng(std::random_device{}()) {}

    int getRandom() {
        int result = head->val;
        ListNode* cur = head->next;
        int i = 2; // we've already considered the 1st node
        while (cur) {
            std::uniform_int_distribution<int> dist(1, i);
            if (dist(rng) == 1) result = cur->val; // replace with prob 1/i
            cur = cur->next;
            ++i;
        }
        return result;
    }
};
