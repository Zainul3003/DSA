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
//--------------------------------------------------------------------------

int knapSack(int Wt, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(Wt+1,0));
       for(int w=wt[0];w<=Wt;w++)dp[0][w]=val[0];
       for(int i=1;i<n;i++)
       {
           for(int W=0;W<=Wt;W++)
           {
                int notpick=dp[i-1][W];
                int pick=INT_MIN;
                if(wt[i]<=W)pick=val[i]+dp[i-1][W-wt[i]];
                dp[i][W]=max(pick,notpick);
           }
       }
       return dp[n-1][Wt];
    }
