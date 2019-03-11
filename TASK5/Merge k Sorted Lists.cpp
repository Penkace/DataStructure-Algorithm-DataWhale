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
// 定义优先队列的排列顺序
struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 建立一个从小到大排序的优先队列
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
        // 创建存储最终结果的虚拟头结点
        ListNode* dummy=new ListNode(0);
        // 判断有多少个队列，即k
        int l=lists.size();
        for(int i=0;i<l;i++){
        // 取出每一个队列的头结点
            if(lists[i]) pq.push(lists[i]);
        }
        // 建立一个pre指向前一个结点
        ListNode* pre=dummy;
        ListNode* cur=NULL;
        // 每次有节点从优先队列出队，就把该结点的子节点入队
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            pre->next=cur;
            pre=pre->next;
            if(pre->next){
                pq.push(pre->next);    
            }
            
        }
        return dummy->next;
    }
};
