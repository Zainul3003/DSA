 void BFS(int i,int j,vector<vector<char>>& grid,vector<vector<int>> &vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int dx[8]={0,-1,-1,-1,0,1,1,1};
        int dy[8]={-1,-1,0,1,1,1,0,-1};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!='1' || vis[nx][ny]==1)continue;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    ans++;
                    BFS(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
