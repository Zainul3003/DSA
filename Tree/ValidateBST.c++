class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return valid(root,LONG_MIN,LONG_MAX);
    }
    bool valid(TreeNode* root,long mini,long maxi)
    {
        if(root==NULL)return true;
        if(root->val<=mini || root->val>=maxi)return false;
        return valid(root->left,mini,root->val) && valid(root->right,root->val,maxi);
    }
};
