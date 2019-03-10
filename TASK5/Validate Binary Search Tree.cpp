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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int>res;
        // 做一个中序遍历
        Inorder(root,res);
        // 因为中序遍历就是左 中 右的顺序，所以比较的时候用左中右的顺序来，只要res[i]>res[i+1]的情况出现，就说明不是有效的二叉树
        for(int i=0;i<res.size()-1;i++){
            if(res[i]>=res[i+1]) return false;
        }
        return true;
    }
    void Inorder(TreeNode* node,vector<int>&res){
        if(!node) return;
        Inorder(node->left,res);
        res.push_back(node->val);
        Inorder(node->right,res);
    }
};
