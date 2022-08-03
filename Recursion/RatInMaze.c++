class Solution{
    public:
    void solve(int i,int j,int n,vector<vector<int>> &m,string s,vector<string> &ans,vector<vector<int>> &vis)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        //downward
        if(i+1<n && !vis[i+1][j] && m[i+1][j])
        {
            vis[i][j]=1;
            solve(i+1,j,n,m,s+'D',ans,vis);
            vis[i][j]=0;
        }
        //left
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1])
        {
            vis[i][j]=1;
            solve(i,j-1,n,m,s+'L',ans,vis);
            vis[i][j]=0;
        }
        //right
        if(j+1<n && !vis[i][j+1] && m[i][j+1])
        {
            vis[i][j]=1;
            solve(i,j+1,n,m,s+'R',ans,vis);
            vis[i][j]=0;
        }
        //upward
        if(i-1>=0 && !vis[i-1][j] && m[i-1][j])
        {
            vis[i][j]=1;
            solve(i-1,j,n,m,s+'U',ans,vis);
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> ans;
        string s="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0])solve(0,0,n,m,s,ans,vis);
        return ans;
    }
};
