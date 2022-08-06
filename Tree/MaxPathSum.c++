class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int maxi=INT_MIN;
        help(root,maxi);
        return maxi;
    }
    int help(TreeNode* root,int &maxi)
    {
        if(root==NULL)return 0;
        int l=max(0,help(root->left,maxi));
        int r=max(0,help(root->right,maxi));
        maxi=max(maxi,l+r+root->val); 
        return root->val+max(l,r);
    }
};
