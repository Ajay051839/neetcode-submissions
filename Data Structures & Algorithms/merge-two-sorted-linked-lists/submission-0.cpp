class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the start of the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        // Traverse both lists and attach the smaller value to the tail
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next; // Advance the tail pointer
        }
        
        // Attach any remaining nodes from temp1 or temp2
        if (temp1 != nullptr) {
            tail->next = temp1;
        } else {
            tail->next = temp2;
        }
        
        // The real head is the next node after the dummy
        ListNode* mergedHead = dummy->next;
        delete dummy; // Clean up memory for the dummy node
        
        return mergedHead;
    }
};