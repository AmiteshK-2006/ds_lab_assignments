void pre(TreeNode*root , vector<int>&ans){
    if(!root) return ;
    ans.push_back(root->val);
    solve(root->left , ans);
    solve(root->right , ans);
}

void in(TreeNode*root, vector<int>&ans){
    if(!root) return;
    solve(root->left , ans);
    ans.push_back(root->val);
    solve(root->right , ans);
}

void post(TreeNode*root , vector<int>&ans){
    if(!root) return;
    solve(root->left , ans);
    solve(root->right , ans);
    ans.push_back(root->val);
}