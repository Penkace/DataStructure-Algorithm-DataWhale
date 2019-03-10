/*********************************************
  >File Name: Binary Tree Traversal (Preorder Traversal, Postorder Traversal, Inorder Traversal)
  >Author: Peng Kai
  >Date: 2018-10-17
*********************************************/

class TreeNdoe{
public:
    int val;
    TreeNode *left,*right;
    TreeNode(int val){
        this->val=val;
        this->left=this->right=NULL;
     }
}
/********************************Preorder Traversal******************************************/

vector<int> PreorderTraversal(TreeNode * root){
    stack<TreeNode*>temp;
    vector<int>result;
    if(root==NULL) return result;
    
    while(root!=NULL||!temp.empty()){
          while(root!=NULL){
              result.push_back(root->val);
              temp.push(root);
              root=root->left;
          }
          if(!temp.empty()){
            root=temp.top();
            temp.pop();
            root=root->right;
          }
    }
    return result;
}

/********************************Inorder Traversal******************************************/

vector<int> InorderTraversal(TreeNode* root){
    stack<TreeNode*> temp;
    vector<int>result;
    if(root==NULL) return result;
    
    while(root!=NULL||!temp.empty()){
        if(root!=NULL){
            temp.push(root);
            root=root->left;
        }
        else{
            root=temp.top();
            temp.pop();
            result.push_back(root->val);
            root=root->right;
        }
    }
    return result;
}

/********************************Postorder Traversal******************************************/

vector<int> PostorderTraversal(TreeNode * root){
    stack<TreeNode> temp;
    vector<int> result;
    if(root==NULL) return result;    
    TreeNode * lastNode=NULL;
    
    while(root!=NULL){
        temp.push(root);
        root=root->left;
    }
    
    while(!temp.empty()){
      root=temp.top();
      temp.pop();
      if(root->right==NULL||root->right==lastNode){
            result.push_back(root->val);
            lastNode=root;
       }
       else{
            temp.push(root);
            root=root->right;
            while(root!=NULL){
                 temp.push(root);
                 root=root->right;
            }
       }
    }
    return result;    
}
