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
 struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on node values
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>, Compare> pq;
    for(ListNode* list : lists){
        if(list) pq.push(list);

    }  
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(!pq.empty()){
        ListNode* minNode = pq.top();
        pq.pop();
        tail->next=minNode;
        tail=tail->next;
        if(minNode->next){
            pq.push(minNode->next);
        }
    }
    return dummy.next;
    }
};