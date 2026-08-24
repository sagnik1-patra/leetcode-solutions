class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* beforeA = list1;

        for (int i = 0; i < a - 1; i++) {
            beforeA = beforeA->next;
        }

        ListNode* afterB = beforeA;

        for (int i = 0; i < b - a + 2; i++) {
            afterB = afterB->next;
        }

        ListNode* tail2 = list2;

        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }

        beforeA->next = list2;
        tail2->next = afterB;

        return list1;
    }
};