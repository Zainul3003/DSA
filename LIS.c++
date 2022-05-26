USING RECURSION AND MEMOZATION
-------------------------------------------------------------------
class Solution {
public:
    int f(int index,int pre_index,vector<int>& nums,int n,vector<vector<int>> &dp)
    {
        if(index==n)return 0;
        if(dp[index][pre_index+1]!=-1)return dp[index][pre_index+1];
        int length=0+f(index+1,pre_index,nums,n,dp);
        if(pre_index==-1 || nums[index]>nums[pre_index])
        {
            length=max(length,1+f(index+1,index,nums,n,dp));
        }
        return dp[index][pre_index+1]=length;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};
----------------------------------------------------------------------------
