/**************************************************************
          Problem: Merge k Sorted Lists
          Solution: Use priority queue to sort the ListNode's values. According to the idea of divide and conquer, we push the head node
                    into the priority queue. When this node token out the queue, push the next of this node.
          Date: 2019-2-27 15:10
**************************************************************/

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
struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use priority to store listnodes
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
        // build a virtual head node
        ListNode* dummy=new ListNode(0);
        int l=lists.size();
        for(int i=0;i<l;i++){
            // head nodes are pushed into priority queue and sort from small to large
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode* pre=dummy;
        ListNode* cur=NULL;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            pre->next=cur;
            pre=pre->next;
            // push the next of this node into the priority queue
            if(pre->next){
                pq.push(pre->next);    
            }
            
        }
        return dummy->next;
    }
};
