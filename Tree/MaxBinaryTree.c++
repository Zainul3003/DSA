class Solution {
private:
    int findM(vector<int>& nums,int l,int h)
    {
        int mx=INT_MIN;
        int ind=l;
        for(int i=l;i<=h;i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                ind=i;
            }
        }
        return ind;
    }
    TreeNode* solve(vector<int>& nums,int l,int h)
    {
        if(l>h)return NULL;
        if(l==h)return new TreeNode(nums[l]);
        int m=findM(nums,l,h);
        TreeNode* root=new TreeNode(nums[m]);
        root->left=solve(nums,l,m-1);
        root->right=solve(nums,m+1,h);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return solve(nums,0,nums.size()-1);
    }
};
