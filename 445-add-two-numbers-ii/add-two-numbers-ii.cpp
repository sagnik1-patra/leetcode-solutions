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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1, s2;
        for (auto p = l1; p; p = p->next) s1.push(p->val);
        for (auto p = l2; p; p = p->next) s2.push(p->val);

        int carry = 0;
        ListNode* head = nullptr; // result built in reverse by prepending

        while (!s1.empty() || !s2.empty() || carry) {
            int a = 0, b = 0;
            if (!s1.empty()) { a = s1.top(); s1.pop(); }
            if (!s2.empty()) { b = s2.top(); s2.pop(); }

            int sum = a + b + carry;
            carry = sum / 10;
            auto* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        return head;
    }
};
