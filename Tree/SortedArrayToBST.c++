class Solution {
public:
    TreeNode* merger(int l,int h,vector<int>& nums)
    {
        if(h<l)return NULL;
        int m=l+(h-l)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=merger(l,m-1,nums);
        root->right=merger(m+1,h,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n=nums.size()-1;
        if(n==0)return NULL;
        return merger(0,n,nums);
    }
};
