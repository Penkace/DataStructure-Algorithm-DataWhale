#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

// 构建一个链表
ListNode* createlinkList(int arr[], int n) {
	if (n == 0) return NULL;
	ListNode* head = new ListNode(arr[0]);
	ListNode* cur = head;
	for (int i = 1; i < n; i++) {
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}
	return head;
}

// 打印一个链表
void printlinkList(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->val << " -> ";
		cur = cur->next;
	}
	cout << "NULL" << endl;
	return;
}

// 删除一个链表
void deletelinkList(ListNode *head) {
	ListNode *cur = head;
	while (cur != NULL) {
		ListNode *del = cur;
		cur = cur->next;
		delete del;
	}
	return;
}

class Solution {
public:
	// 翻转一个链表，O(n)时间复杂度，O(1)空间复杂度
	ListNode * reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* cur = head;
		//ListNode* next = head->next;// 要保证head不为空，不然这句话不安全
		while (cur != NULL) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
	// 合并多个链表
	struct cmp {
		bool operator()(ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// 创建一个有小到大排序的优先队列
		priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
		// 创建一个虚拟头结点，有助于理解
		ListNode* dummy = new ListNode(0);
		int l = lists.size();
		// 选取lists 中每个链表的头结点放入到优先队列中
		for (int i = 0; i < l; i++) {
			if (lists[i]) pq.push(lists[i]);
		}

		ListNode* pre = dummy;
		ListNode* cur = NULL;
		while (!pq.empty()) {
			cur = pq.top();
			pq.pop();
			pre->next = cur;
			pre = pre->next;
			// 放入dummy链表中的结点的子节点如果有下一个节点，则放入到优先队列中
			if (pre->next) {
				pq.push(pre->next);
			}
		}
		return dummy->next;
	}
};

int main() {
	int arr[] = { 1,2,3,4,5 }; //改变初值即可
	int n = sizeof(arr) / sizeof(int);
	// 完成链表的创建、翻转、打印
	ListNode* head = createlinkList(arr, n);
	printlinkList(head);
	ListNode *newhead = Solution().reverseList(head);
	printlinkList(newhead);

	// 完成两个链表的合并
	int arr2[] = { 2,4,6,8,10 };
	int n2 = sizeof(arr2) / sizeof(int);;
	ListNode* head2 = createlinkList(arr2, n2);
	printlinkList(head2);
	vector<ListNode*> lists;
	lists.push_back(head);
	lists.push_back(head2);
	ListNode *newhead2 = Solution().mergeKLists(lists);
	printlinkList(newhead2);

	// C++创建之后需要自己删除空间
	deletelinkList(newhead);
	deletelinkList(head);
	deletelinkList(head2);
	deletelinkList(newhead2);
	system("pause");
	return 0;
}
