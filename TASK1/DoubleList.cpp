#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* pre;
	ListNode* next;
	ListNode(int x) :val(x), pre(NULL), next(NULL) {}
};
ListNode* createdoublelist(int arr[], int n) {
	if (n == 0) return NULL;

	ListNode *head = new ListNode(arr[0]);
	ListNode *cur = head;
	ListNode *bef = head;
	for (int i = 1; i < n; i++) {
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
		cur->pre = bef;
		bef = cur;
	}
	return head;
}

void printdoubleList(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->val << " ->" << endl;
		cur = cur->next;
	}
	cout << "NULL" << endl;
	return;
}

// 删除值为i的结点
ListNode* deleteNode(ListNode* head,int i) {
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	ListNode* cur = dummyhead;
	// 建立虚拟头结点能够优化while的判断条件，如果直接指向头结点需要再判断头结点是否为空
	while (cur->next != NULL) {
		// 删除的时候，先建立一个指向被删除结点的结点，然后调整该结点前后的两个结点的next和pre指针所指向的结点，最后再释放del结点的空间，完成删除
		if (cur->next->val == i) {
			ListNode* del = cur->next;
			cur->next = del->next;
			del->next->pre = cur;
			delete del;
		}
		else {
			cur = cur->next;
		}
	}
	// 使用虚拟头结点的另一个好处就是如果head本来就为空，那么就不执行上面的循环，直接在后面返回NULL，不用另外再写代码；
	ListNode* retNode = dummyhead->next;
	delete dummyhead;
	return retNode;
}

// 删除整个双向链表
void deletedoubleList(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		ListNode *del = cur;
		cur = cur->next;
		delete del;
	}
	return;
}

// 在链表的某一点插入结点
ListNode* insertinLink(ListNode* head, int i,int val) {
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	ListNode* cur = dummyhead;
	// 先找到第i-1个结点处
	for (int j = 0; j<i; j++) {
		cur = cur->next;
	}
	ListNode* bef = cur;
	cur = cur->next;
	ListNode* ins = new ListNode(val);
	bef->next = ins;
	ins->pre = bef;
	cur->pre = ins;
	ins->next = cur;
	ListNode* retNode = dummyhead->next;
	delete dummyhead;
	return retNode;
}

class Solution {
public:
	// 查找中间结点，我采用的思路是快慢指针，当快指针的下一个节点是NULL时，那么此时的slow指针指向的就是中间结点；
	ListNode* searchmidnode(ListNode* head) {
		ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;
		ListNode* fast = dummyhead->next;
		ListNode* slow = dummyhead->next;
		// 至少有两个结点才有中间结点
		while (fast->next != NULL&& fast->next->next!=NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		delete dummyhead;
		return slow;
	}
};

int main() {
	int arr[] = { 1,2,3,4,5,6 };
	// 这样求链表长度的好处是，如果更改了数组的内容，我们只需要修改数组的内容
	int n = sizeof(arr) / sizeof(int);
	ListNode *head = createdoublelist(arr, n);
	printdoubleList(head);

	ListNode *midNode = Solution().searchmidnode(head);
	cout << midNode->val << endl;
	deletedoubleList(head);
	delete midNode;
	return 0;
}
