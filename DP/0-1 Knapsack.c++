int f(int i,int W,int wt[], int val[],vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(wt[0]<=W)return val[0];
            else return 0;
        }
        if(dp[i][W]!=-1)return dp[i][W];
        int notpick=f(i-1,W,wt,val,dp);
        int pick=INT_MIN;
        if(wt[i]<=W)pick=val[i]+f(i-1,W-wt[i],wt,val,dp);
        return dp[i][W]=max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(n-1,W,wt,val,dp);
    }
