class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        bool inComponent = false;

        while (head) {
            if (s.count(head->val)) {
                if (!inComponent) {
                    count++;
                    inComponent = true; // Start of a new component
                }
            } else {
                inComponent = false; // End of a component
            }
            head = head->next;
        }

        return count;
    }
};