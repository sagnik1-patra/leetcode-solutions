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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k, nullptr);
        int n = 0;
        ListNode* curr = head;

        // Step 1: Count total length
        while (curr) {
            ++n;
            curr = curr->next;
        }

        int partSize = n / k;
        int extra = n % k;

        curr = head;
        for (int i = 0; i < k && curr; ++i) {
            parts[i] = curr;
            int currentPartSize = partSize + (extra > 0 ? 1 : 0);
            extra--;

            // Move (currentPartSize - 1) steps forward
            for (int j = 1; j < currentPartSize; ++j) {
                curr = curr->next;
            }

            // Cut the link
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return parts;
    }
};
