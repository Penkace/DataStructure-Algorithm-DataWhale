//下面将用数据的形式来生成二叉树
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

const int N = 100;
struct TreeNode {
	int val;
	TreeNode *leftChild;
	TreeNode *rightChild;
	TreeNode(int xx) : val(xx), leftChild(NULL), rightChild(NULL) {}
};
TreeNode* createNode(int data) {
	TreeNode* tmp = new TreeNode(data);
	return tmp;
}

TreeNode* createTree(int arr[]) {
	TreeNode* tmp = new TreeNode(arr[0]);
	TreeNode* node[N] = { NULL };
	int l = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < l; i++) {
		node[i] = createNode(arr[i]);
	}
	for (int i = 0; i < l / 2; i++) {
		node[i]->leftChild = node[2 * i+1];
		node[i]->rightChild = node[2 * i + 2];
	}
	return node[0];
}
int getdepth(TreeNode* root) {
	if (root == NULL) return 0;
	return max(1 + getdepth(root->leftChild), 1 + getdepth(root->rightChild));
}
bool searchNode(TreeNode* root,int &data) {
	return (root->val==data)||searchNode(root->leftChild,data)||searchNode(root->rightChild,data);
}

void preorder(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> res;
	if (root == NULL) return;
	s.push(root);
	while (!s.empty()){
		while (root->leftChild != NULL) {
			res.push_back(root->val);
			s.push(root->leftChild);
			root = root->leftChild;
		}
		// 返回得到栈上面的树节点
		root = s.top();
		// 判断这个树节点是否存在有节点，存在则继续循环，不存在则出栈
		if (root->rightChild != NULL) 
			root = root->rightChild;
		else {
			s.pop();
			root = s.top();
		}
	}
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
		cout << *it << endl;
	}
	return;
}

void insert(TreeNode* root, int val) {
	if (root == NULL) {
		TreeNode *tmp = new TreeNode(val);
		root = tmp;
		delete tmp;
		return;
	}
	else {
		if (val < root->val) {
			insert(root->leftChild, val);
		}
		else {
			insert(root->rightChild, val);
		}
	}
}
int main() {
	TreeNode* root;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	root = createTree(arr);
	preorder(root);
	system("pause");
	return 0;
}
