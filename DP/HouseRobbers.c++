//------RECURSION+MEMOIZATION-------------------

int rec(int ind,vector<int> &nums,vector<int> &dp)
{
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=nums[ind]+rec(ind-2,nums,dp);
    int npick=rec(ind,nums,dp);
    return dp[ind]=max(pick,npick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
        int n=nums.size();
        vector<int> dp(n,-1);
        return rec(n-1,nums,dp);
}

//------TOP DOWN-------------------------------------
int FindMaxSum(int a[], int n)
    {
        vector<int> dp(n,0);
        dp[0]=a[0];
        for(int i=1;i<n;i++)
        {
            int pick=a[i];
            if(i>1)pick+=dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
