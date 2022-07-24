class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) 
    {
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(arr[0] <= k)dp[0][arr[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=k;target++)
            {
                bool nottake=dp[ind-1][target];
                bool take=false;
                if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]];
                dp[ind][target]= take | nottake;
            }
        }
        return dp[n-1][k];
   }
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum&1)return false;
        sum/=2;
        return subsetSumToK(n,sum,nums); 
    }
};
