class Solution {
public:
    int f(string &a,string &b,int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 || j==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i-1]==b[j-1])return dp[i][j]=1+f(a,b,i-1,j-1,dp);
        return dp[i][j]=max(f(a,b,i-1,j,dp),f(a,b,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(text1,text2,m,n,dp);
    }
};
//------------------------------------------------------------

int longestCommonSubsequence(string text1, string text2)
    {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
