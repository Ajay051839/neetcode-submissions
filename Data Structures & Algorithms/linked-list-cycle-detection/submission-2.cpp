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
    bool hasCycle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return false;
        ListNode* slow=head;
        if((head->next->next)==nullptr)return false;
        ListNode* fast=head->next->next;
        while(fast->next!=nullptr){
            if(slow==fast)return true;
            slow=slow->next;
            if((fast->next->next)==nullptr)return false;
            fast=fast->next->next;
        }
        return false;
    }
};
