/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // 如果一开始就是空节点，则返回false
        if (root == NULL) return false;
        // 根据题目的意思，一定要遍历到树的底部并且sum等于子节点的值时才返回true
        if (root->left == NULL && root->right == NULL && root->val == sum ) return true;
        // 如果没有达到底部，则继续遍历，进行左右结点的递归，带入的sum值要减。
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
