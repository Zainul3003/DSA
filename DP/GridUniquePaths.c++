//-----------------TOP DOWN----------------\\
int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int>(b,-1));
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(i==0 && j==0)dp[i][j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[a-1][b-1];
 
 //-------------------MEMOIZATION------------------\\
 int path(int i,int j,vector<vector<int>> &dp)
    {
       if(i==0 && j==0)return 1;
       if(i<0 || j<0)return 0;
       if(dp[i][j]!=-1)return dp[i][j];
       int up=path(i-1,j,dp);
       int left=path(i,j-1,dp);
       return dp[i][j]=(up+left);
    }
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return path(a-1,b-1,dp);
    }
