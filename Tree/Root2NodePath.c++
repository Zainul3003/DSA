bool solveT(TreeNode* root, int B,vector<int> &ans)
{
    if(!root)return false;
    ans.push_back(root->val);
    if(root->val==B)return true;
    if(solveT(root->left,B,ans) || solveT(root->right,B,ans))return true;
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* root, int B) 
{
    vector<int> ans;
    if(!root)return ans;
    solveT(root,B,ans);
    return ans;
}
