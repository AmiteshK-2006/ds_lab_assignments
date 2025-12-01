TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return NULL;
    if(root->val==val) return root;
    if(root->val>val) return searchBST(root->left , val);
    else return searchBST(root->right , val);
}

TreeNode* findMax(Node *root) {
    if(!root) return NULL;
    TreeNode*node=root;
    while(node->right) node=node->right;
    return node;
}

TreeNode* findMin(Node *root) {
    if(!root) return NULL;
    TreeNode*node=root;
    while(node->left) node=node->left;
    return node;
}

int inOrderSuccessor(Node *root, Node *x) {
    if(x->right) return findMin(x->right);
    
    Node*dummy=NULL;
    while(true){
        if(root->data > x->data){
            dummy=root;
            root=root->left;
        }else if(root->data < x->data){
            root=root->right;
        }else break;
    }
    return (dummy)?dummy->data:-1;
}


node* inorderPredecessor(node* root, node* target) {
    if(target->lchild!=NULL) return findMax(target->lchild);

    node* pred=NULL;
    while(root!=NULL) {
        if(target->data > root->data) {
            pred=root;
            root=root->rchild;
        } 
        else if(target->data<root->data) {
            root=root->lchild;
        } 
        else break;
    }
    return pred;
}

