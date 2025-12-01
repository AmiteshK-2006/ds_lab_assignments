class Solution {
    TreeNode*flag=NULL;
    long long sum;
    void solve(TreeNode*root){
        if(!root) return;
        if(!root->left && !root->right){
            flag=root;
            return;
        }
        solve(root->left);
        if(root->left && root->left==flag) sum+=flag->val;
        solve(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        sum=0;
        solve(root);
        return sum;
    }
};




int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}



vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    if(!root) return ans;
    queue<pair<TreeNode* , int>>q;
    q.push({root , 0});
    while(!q.empty()){
        int n=q.size();
        for(int i=0 ; i<n ; i++){
            auto [node , x]=q.front(); q.pop();
            if(node->left) q.push({node->left , x+1});
            if(node->right) q.push({node->right , x+1});
            if(i==n-1) ans.push_back(node->val);
        }
    }
    return ans;
}




