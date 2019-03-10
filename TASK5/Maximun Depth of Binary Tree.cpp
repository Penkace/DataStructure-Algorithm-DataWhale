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
    int maxDepth(TreeNode* root) {
    // 遍历到空节点就返回0
        if(root==NULL)
            return 0;
            // 每遍历一层就加1
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
