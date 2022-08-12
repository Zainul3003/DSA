class Solution {
public:
	const int M=1e9+7;
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
			up=1+f(i-1,j,m,n,grid,dp);
		}
		int down=0;
		if(check(i+1,j,m,n) and grid[i][j]<grid[i+1][j])
		{
			down=1+f(i+1,j,m,n,grid,dp);
		}
		int left=0;
		if(check(i,j-1,m,n) and grid[i][j]<grid[i][j-1])
		{
			left=1+f(i,j-1,m,n,grid,dp);
		}
		int right=0;
		if(check(i,j+1,m,n) and grid[i][j]<grid[i][j+1])
		{
			right=1+f(i,j+1,m,n,grid,dp);
		}
		return dp[i][j]=(up+down+right+left)%M;
	}
	int countPaths(vector<vector<int>>& grid) 
	{
		int m=grid.size();
		int n=grid[0].size();
		vector<vector<int>> dp(m,vector<int>(n,-1));
		int ans=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				 ans=(ans+f(i,j,m,n,grid,dp))%M;
			}
		}
		return ans%M+(m*n);
	}
};




///////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
	const int M=1e9+7;
	int f(int i,int j,int mm,int n,vector<vector<int>>& m,vector<vector<int>>& dp)
	{
		if(i<0 or j<0 or i>=mm or j>=n)return 0;

		if(dp[i][j]!=-1)return dp[i][j];

		int ans=1;
		if(i>0 and m[i][j]<m[i-1][j])
		{
			ans+=f(i-1,j,mm,n,m,dp);
		}
		if(i+1<mm and m[i][j]<m[i+1][j])
		{
			ans+=f(i+1,j,mm,n,m,dp);
		}
		if(j>0 and m[i][j]<m[i][j-1])
		{
			ans+=f(i,j-1,mm,n,m,dp);
		}
		if(j+1<n and m[i][j]<m[i][j+1])
		{
			ans+=f(i,j+1,mm,n,m,dp);
		}
		return dp[i][j]=ans%M;
	}
	int countPaths(vector<vector<int>>& matrix) 
	{
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int> (n, -1));
		long long ans=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans+=f(i,j,m,n,matrix,dp);
			}
		}
		return ans%M;
	}
};
