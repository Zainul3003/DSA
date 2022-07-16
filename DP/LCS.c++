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
