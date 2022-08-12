class Solution {
public:
    
    bool check(int i,int j,int rows,int cols)
    {
        if(i<0 || j<0 || i>=rows || j>=cols)return false;
        return true;
    }
    int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0 || i >=m || j >=n) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=0;
        if(check(i-1,j,m,n) and grid[i][j]<grid[i-1][j])
        {
            up=f(i-1,j,m,n,grid,dp);
        }
        int down=0;
        if(check(i+1,j,m,n) and grid[i][j]<grid[i+1][j])
        {
            down=f(i+1,j,m,n,grid,dp);
        }
        int left=0;
        if(check(i,j-1,m,n) and grid[i][j]<grid[i][j-1])
        {
            left=f(i,j-1,m,n,grid,dp);
        }
        int right=0;
        if(check(i,j+1,m,n) and grid[i][j]<grid[i][j+1])
        {
            right=f(i,j+1,m,n,grid,dp);
        }
        return dp[i][j]=1+max(up,max(down,max(right,left)));
    }
    int longestIncreasingPath(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 ans=max(ans,f(i,j,m,n,grid,dp));
            }
        }
        return ans;
    }
};
