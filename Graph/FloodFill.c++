class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        q.push({sr,sc});
        int t=image[sr][sc];
        image[sr][sc]=color;
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny]==1 || image[nx][ny]!=t)continue;
                image[nx][ny]=color;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
        return image;
    }
};
