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
    TreeNode* invertTree(TreeNode* root) {
        // 为空就返回
        if(root==NULL){
            return NULL;
        }
        // 不为空就继续往下遍历，直到左右子结点不为空
        invertTree(root->left);
        invertTree(root->right);
        // 到达了树的底部，开始从这里翻转左右子节点
        swap(root->left,root->right);
        return root;
    }
};
