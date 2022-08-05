class Solution {
public:
    int f(int target,vector<int>& nums,vector<int> &dp)
    {
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
           ans+=f(target-nums[i],nums,dp); 
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target)
    {
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return f(target,nums,dp);
    }
};
//--------------------------------------------------------------------------------------------

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int n=nums.size();
        vector<int> dp(target+1,0);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=nums[j])dp[i]+=dp[i-nums[j]]; 
            }
        }
        return dp[target];
    }
};
