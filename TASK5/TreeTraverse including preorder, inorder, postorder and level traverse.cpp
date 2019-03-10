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
    // 先序遍历的原则的左节点边入栈边进入输出数组，到了最低端的左节点时，开始判断右节点是否存在，如果存在则开始遍历右节点
    // 对右节点执行和刚开始时一样的操作，一直遍历到左节点的底端并且不断地输出结果
    while(root!=NULL||!temp.empty()){
          while(root!=NULL){
              result.push_back(root->val);
              temp.push(root);
              root=root->left;
          }
          if(!temp.empty()){
            // 一旦都遍历完了就出栈
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
    // 中序遍历的原则是每次栈的最后一个输出
    while(root!=NULL||!temp.empty()){
        // 每次都要遍历左节点到最后
        if(root!=NULL){
            temp.push(root);
            root=root->left;
        }
        else{
            // 当遍历到底时，就取栈最后的元素并且放入输出vector
            root=temp.top();
            temp.pop();
            result.push_back(root->val);
            // 判断是否有右节点，中序遍历最后才遍历右节点及其子树
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
    // 后序遍历有个麻烦的地方就是需要记录这个结点的右节点是否遍历过，如果没遍历过则需要遍历，如果遍历过了就出栈并且进入输出vector中
    TreeNode * lastNode=NULL;
    // 常规操作，遍历左边
    while(root!=NULL){
        temp.push(root);
        root=root->left;
    }
    // 只要stack不为空，则取最后一个元素进行输出并且判断是否有右节点，如果有，则记录当前的结点，出栈，然后开始遍历右节点
    while(!temp.empty()){
      // 取出栈顶元素
      root=temp.top();
      temp.pop();
      // 没有右节点或者该结点的右节点已经遍历过了，就进入到输出队列
      if(root->right==NULL||root->right==lastNode){
            result.push_back(root->val);
            lastNode=root;
       }
      // 如果有右节点并且该结点的子树没有遍历过，则开始遍历右节点的子树
       else{
            temp.push(root);
            root=root->right;
          // 右子树的左节点全部入栈
            while(root!=NULL){
                 temp.push(root);
                 root=root->right;
            }
       }
    }
    return result;    
}
