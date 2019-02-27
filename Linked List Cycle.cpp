/*******************************************************
      Problem: Linked List Cycle
      Solution: Use the idea of fast pointer and slow pointer. If it's a linked list cycle, the fast pointer and the slow pointer will meet.
      Date: 2019-2-27 12:04
*******************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* fast =head;
        ListNode* slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
