TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode*node=new TreeNode(val);
    if(!root) return node;
    TreeNode*dummy=root;
    while(root->left || root->right){
        if(dummy->val > val){
            if(!dummy->left){
                dummy->left=node;
                break;
            }
            else dummy=dummy->left;
        }else{
            if(!dummy->right){
                dummy->right=node;
                break;
            }
            else dummy=dummy->right;
        }
    }
    return root;
}


TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;
    TreeNode*follow=NULL , *dummy=root;
    while(dummy){
        if(dummy->val==key) break;
        follow=dummy;
        if(dummy->val > key) dummy=dummy->left;
        else dummy=dummy->right;
    }
    if(!dummy) return root;

    //leaf
    if(!dummy->left && !dummy->right){
        if(dummy==root) return NULL;
        if(follow->left==dummy) follow->left=NULL;
        else follow->right=NULL;
        return root;
    }

    //1 child
    if(!dummy->left || !dummy->right){
        if(dummy==root){
            if(root->left) return root->left;
            else return root->right;
        }
        if(dummy->left){
            if(follow->left==dummy) follow->left=dummy->left;
            else follow->right=dummy->left;
        }else{
            if(follow->left==dummy) follow->left=dummy->right;
            else follow->right=dummy->right;
        }
        return root;
    }

    //2 childern
    follow=dummy;
    TreeNode*succ=dummy->right;
    while(succ->left){
        follow=succ;
        succ=succ->left;
    }
    dummy->val=succ->val;
    if(!succ->left && !succ->right){
        if(follow->left==succ) follow->left=NULL;
        else follow->right=NULL;
        return root;
    }else{
        if(follow->left==succ) follow->left=succ->right;
        else follow->right=succ->right;
        return root;
    }
    return NULL;
}


int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}


