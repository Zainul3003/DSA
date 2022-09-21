class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int r,int c,vector<pair<int,int>> &temp)
    {
        vis[row][col]=1;
        temp.push_back({row-r,col-c});
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
            {
                dfs(nx,ny,vis,grid,r,c,temp);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    //cout<<i<<" "<<j<<" ";
                    vector<pair<int,int>> temp;
                    dfs(i,j,vis,grid,i,j,temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
