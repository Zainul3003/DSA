class Solution {
public:
    int f(int i,int sum,vector<int>& coins,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(sum%coins[0]==0)return sum/coins[0];
            else return 1e9;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int notpick=0+f(i-1,sum,coins,dp);
        int pick=INT_MAX;
        if(coins[i]<=sum)pick=1+f(i,sum-coins[i],coins,dp);
        return dp[i][sum]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9)return -1;
        else return ans;
    }
};
//////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> pre(amount+1,0);
        vector<int> cur(amount+1,0);
        for(int sum=0;sum<=amount;sum++)
        {
            if(sum%coins[0]==0)pre[sum]=sum/coins[0];
            else pre[sum]=1e9;
        }
        for(int i=1;i<n;i++)
        {
            for(int sum=0;sum<=amount;sum++)
            {
                int notpick=pre[sum];
                int pick=INT_MAX;
                if(coins[i]<=sum)pick=1+cur[sum-coins[i]];
                cur[sum]=min(pick,notpick);
            }
            pre=cur;
        }
        int ans=pre[amount];
        if(ans>=1e9)return -1;
        else return ans;
    }
};
